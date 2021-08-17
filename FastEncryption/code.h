#ifndef _code_h_
#define _code_h_
#include <iostream>
#include <string>
#include <thread>
#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <array>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include "lib/aes.h"
#include "lib/modes.h"      
#include "lib/filters.h"  

using namespace std;
using namespace CryptoPP;

void debugNote(string note,int value)
{
	bool debugMode = false;
	if(debugMode)
	{
		cout << note << " " << value << endl;
	}
}
// This class is for AES
class stringAesCypher
{
public:
	void encode (string data,string Skey,string &out)
	{
		byte key[16];
		byte iv[16];
		string bin;
		string theKey(Skey);
		int i(0);
		theKey.append("t;rke;tlrke65409654ytr");

		while(i != 16)
		{
			key[i] = theKey[i];
			iv[i] = theKey[i];
			i++;
		}
		// Encryptor
		CryptoPP::ECB_Mode< CryptoPP::AES >::Encryption 
		//Encryptor( key, sizeof(key), iv );
		Encryptor( key, sizeof(key));
	  
	  // Encryption
	  CryptoPP::StringSource( data, true,
		new CryptoPP::StreamTransformationFilter( Encryptor,
		  new CryptoPP::StringSink( out )
		) // StreamTransformationFilter
	  ); // StringSource
	}

	void decode (string CT,string Skey,string &out)
	{
		byte key[16];
		byte iv[16];
		string bin;
		string theKey(Skey);
		
		int i(0);
		theKey.append("t;rke;tlrke65409654ytr");
		while(i != 16)
		{
			key[i] = theKey[i];
			iv[i] = theKey[i];
			i++;
		}
		// Decryptor
		CryptoPP::ECB_Mode< CryptoPP::AES >::Decryption
		// Decryptor( key, sizeof(key), iv );
		Decryptor( key, sizeof(key) );

	  // Decryption
	  CryptoPP::StringSource( CT, true,
		new CryptoPP::StreamTransformationFilter( Decryptor,
		  new CryptoPP::StringSink( out )
		) // StreamTransformationFilter
	  ); // StringSource
	}
};
// This class is for Tea the cypher that does not need to be linked
class stringTeaCypher
{
	private:
	void decodeXtea(unsigned int* v, unsigned int* w, unsigned int* k) {
		register unsigned int v0=v[0], v1=v[1], i, sum=0xC6EF3720;
		register unsigned int delta=0x9E3779B9;
		for(i=0; i<32; i++) {
			v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + k[(sum>>11) & 3]);
			sum -= delta;
			v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + k[sum & 3]);
		}
		w[0]=v0; w[1]=v1;
	}
	void encodeXtea(unsigned int* v, unsigned int* w, unsigned int* k) {
		register unsigned int v0=v[0], v1=v[1], i, sum=0;
		register unsigned int delta=0x9E3779B9;
		for(i=0; i<32; i++) {
		   v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + k[sum & 3]);
			sum += delta;
			v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + k[(sum>>11) & 3]);
		}
		w[0]=v0; w[1]=v1;
	}
	void TeaDecode ( const std::string& str, const std::string& key, std::string* out )
	{
		unsigned int v[2];
		unsigned int w[2];
		unsigned int k[4];
		unsigned int keybuffer [ 4 ];

		// Clear buffers
		memset ( v, 0, sizeof(v) );
		memset ( w, 0, sizeof(w) );
		memset ( k, 0, sizeof(k) );
		memset ( keybuffer, 0, sizeof(keybuffer) );
		out->clear ();

		// Count the number of passes that we need
		int numBlocks = str.length() / 4;
		int numPasses = numBlocks - 1;

		if ( numPasses <= 0 )
			return;

		// Process the key
		int len = key.length ();
		if ( len > 16 )
			len = 16;
		memcpy ( keybuffer, key.c_str(), len );
		for ( int i = 0; i < 4; ++i )
			k[i] = keybuffer[i];

		// Create a temporary buffer to store the result
		unsigned char* buffer = new unsigned char [ numPasses * 4 + 4 ];
		memset ( buffer, 0, numPasses * 4 + 4 );

		// Decode it!
		const char* p = str.c_str();
		v[1] = *(unsigned int*)&p[numPasses * 4];
		for ( int i = 0; i < numPasses; ++i )
		{
			v[0] = *(unsigned int*)&p[(numPasses-i-1)*4];
			decodeXtea ( &v[0], &w[0], &k[0] );
			*(unsigned int*)&buffer[(numPasses-i-1)*4] = w[0];
			v[1] = w[1];
		}

		out->assign ( (char *)buffer, numPasses*4 );
		delete [] buffer;
	}
	void TeaEncode ( const std::string& str, const std::string& key, std::string* out )
	{
		unsigned int v[2];
		unsigned int w[2];
		unsigned int k[4];
		unsigned int keybuffer [ 4 ];

		// Clear buffers
		memset ( v, 0, sizeof(v) );
		memset ( w, 0, sizeof(w) );
		memset ( k, 0, sizeof(k) );
		memset ( keybuffer, 0, sizeof(keybuffer) );
		out->clear ();

		// Process the key
		int len = key.length ();
		if ( len > 16 )
			len = 16;
		memcpy ( keybuffer, key.c_str(), len );
		for ( int i = 0; i < 4; ++i )
			k[i] = keybuffer[i];

		// Copy the input string to a buffer of size multiple of 4
		int strbuflen = str.length ();
		if ( strbuflen == 0 )
			return;
		if ( (strbuflen % 4) > 0 )
			strbuflen += 4 - (strbuflen % 4);
		unsigned char* strbuf = new unsigned char [ strbuflen ];
		memset ( strbuf, 0, strbuflen );
		memcpy ( strbuf, str.c_str(), str.length() );

		// Encode it!
		v[1] = 0;
		for ( int i = 0; i < strbuflen; i += 4 )
		{
			v[0] = *(unsigned int*)&strbuf[i];

			encodeXtea ( &v[0], &w[0], &k[0] );
			out->append ( (char*)&w[0], 4 );

			v[1] = w[1];
		}
		out->append ( (char*)&v[1], 4 );

		delete [] strbuf;
	}
	public:
	void encode(string inString,string key,string &out)
	{
		TeaEncode(inString,key,&out);
	}
	void decode(string inString,string key,string &out)
	{
		TeaDecode(inString,key,&out);
	}
};
// The other stuff put into a class
class Core 
{
	private:	
	vector <string> ram;	
	int numberOfBins;
	string mode;
	string key;
	size_t count;
	string coreSet;	
	int encodeSize,decodeSize,bufferSize;
	int theSize;
		void cores(int rRam)
		{
			string ramTemp("");
			stringAesCypher Code;
			//stringTeaCypher Code;

			if(mode == "E")
			{
				Code.encode(ram[rRam],key,ramTemp);				
			}
			if(mode == "D")
			{
				Code.decode(ram[rRam],key,ramTemp);
			}
			ram[rRam] = ramTemp; 
		}
		void startCores()
		{
			thread coreSet[8];
			for(int i = 0; i != numberOfBins; i++){coreSet[i] = thread(&Core::cores,this,i);}
			for(int i = 0; i != numberOfBins; i++){coreSet[i].join();}	
		}
		vector<string> breakSplit(const string& raw, size_t bins) 
		{
			//size_t bins   = 8;
			size_t rawlen = raw.size();
			size_t div    = rawlen / bins;
			size_t excess = rawlen % bins;
			auto pos = raw.cbegin();
			vector<string> fragments(bins);
			for(size_t i = 0; i < bins; ++i) {
				// the first few bins get one of the excess char each
				size_t binlen = div + (i < excess ? 1 : 0); 
				auto nextpos = pos + binlen;
				fragments[i] = string(pos, nextpos);
				pos = nextpos;
			}
			return fragments;
		}
		void unsplitData(string &theMainBuffer)
		{
			theMainBuffer = "";
			//for(int i = 0; i != numberOfBins+1; i++)
			for(int i = 0; i != numberOfBins; i++)			
			{
				theMainBuffer.append(ram[i]);
				ram[i] = "";
				ram[i].resize(0);
			}													
		}
		int giveBins(int size,int blocks)
		{
			if(blocks/size == 0)
			{
				return blocks/size+1;
			}
			else
			{
				return blocks/size;
			}	
		}		
	public:
	Core();
		void setMode(string theMode)
		{
			mode = theMode;
		}
		void setKey(string theKey)
		{
			key = theKey;
		}
		void readFile(string inputFileName,string outputFileName)
		{
			if(mode == "E"){theSize = encodeSize;}
			if(mode == "D"){theSize = decodeSize;}
			int splitPerBin(theSize/8);
			// Size and file streams
			ifstream fileStreamIn(inputFileName,ios::binary);
			ofstream fileStreamOut(outputFileName,ios::binary);	
				while(fileStreamIn)
				{
					string theMainBuffer(bufferSize,'\0');			
					fileStreamIn.read(&theMainBuffer.front(),theSize);// Reads
					count = fileStreamIn.gcount();// Read ammount 
					if(count == 0){break;}
					
					theMainBuffer.resize(count);	
					numberOfBins = giveBins(splitPerBin,count);
					//cout << numberOfBins << " " << count << endl;
					if(numberOfBins >= 2)
					{
						//cout << "Main mode" << endl;
						ram = breakSplit(theMainBuffer,numberOfBins);
					}		
					else
					{
						ram[0] = theMainBuffer;
					}
					startCores();
					unsplitData(theMainBuffer);
					
					fileStreamOut.write(theMainBuffer.c_str(),theMainBuffer.length());	 
				}
			fileStreamIn.close();
			fileStreamOut.close();
		}
};



Core::Core()
{

	/* Tea
	encodeSize = 80000000;
	decodeSize = 80000032;
	bufferSize = 80000034;
	numberOfBins = 0;
	ram.resize(8);
	*/
	encodeSize = 80000000;
	decodeSize = 80000128;
	bufferSize = 80000130;
	numberOfBins = 0;
	ram.resize(8);	
}

#endif
