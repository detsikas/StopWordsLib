//
//  StopSetClass.cpp
//  StopWordsSet
//
//  Created by Nikolaos Detsikas on 4/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "StopSetClass.h"


bool StopSetClass::find(string const & word) const
{
    set<string>::const_iterator it;
    
    it = mySet.find(word);
    
    if (it==mySet.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

void StopSetClass::readFile(string const & path)
{
	string line;
    
	cout<<"\t Reading file: "<<path.c_str()<<endl;
    
	ifstream inFile(path.c_str());
	if (inFile.is_open())
    {
        while(inFile.good())
        {	
            getline(inFile, line);
#ifdef LOG
            cout << "Inserting "<<line<<" ...";
#endif
            pair<set<string>::const_iterator,bool> exists = mySet.insert(line);
#ifdef LOG
            if (exists.second)
                cout<<"done"<<endl;
            else
                cout<<"exists"<<endl;
#endif
        }
        inFile.close();
    }
}


void StopSetClass::readDirectory(string const & path)
{
	DIR* pDir = opendir(path.c_str());
	struct dirent *dirEntry;
    
	cout<<"Reading directory: "<<path.c_str()<<endl;
    
	while ((dirEntry=readdir(pDir))!=NULL)
	{
		if (strcmp(dirEntry->d_name,".") && strcmp(dirEntry->d_name,".."))
		{
			string newPath = path+"/"+dirEntry->d_name;
			if (dirEntry->d_type==DT_REG)
			{
				readFile(newPath);
			}
			else if (dirEntry->d_type==DT_DIR)
			{
				readDirectory(newPath);
			}
		}
	}
    
	closedir(pDir);	
} 
