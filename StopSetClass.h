//
//  StopSetClass.h
//  StopWordsSet
//
//  Created by Nikolaos Detsikas on 4/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef StopWordsSet_StopSetClass_h
#define StopWordsSet_StopSetClass_h

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/set.hpp>

#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <dirent.h>


using namespace std;

class StopSetClass
{
public:
    set<string> mySet;
    
    void readDirectory(string const & path);
    bool find(string const & word) const;

private:
    void readFile(string const & path);
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & mySet;
    }
};

#endif
