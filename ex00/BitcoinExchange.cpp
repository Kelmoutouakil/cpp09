/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:52:29 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/07 10:01:39 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"
bool isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BitcoinExchange::StoreMap()
{
    std::ifstream inputfile;
    inputfile.open("data.csv");
    if(!inputfile.is_open())
        throw std::invalid_argument("open failled!");
    else
    {
        std::string line;
        getline(inputfile,line);
      
        while(std::getline(inputfile,line))
        {
            int i = 0;
            int j = 0;
            std::string s;
            std::string str;
            while(line[i] != ',')
            {
                if(line[i] == '-')
                    i++;
                s[j] = line[i];
                j++;
                i++;
            }
            str = line.substr(i+1,line.length());
            myMap[std::atoi(s.c_str())] = std::atof(str.c_str());
        }
        // std::map<int,double>::iterator it = myMap.begin();
        // for(;it != myMap.end();++it)
        // {
        //     std::cout << it->first<< "    -->"<<it->second<<"\n";
        // }
     }
}

int BitcoinExchange:: dateFormat(std::string& s)
{
    std::string tmp = "0123456789";
    std::string t[3];

    if(s.length() != 11 ||s.find_first_not_of("0123456789- ")!= std::string::npos)
         throw std::runtime_error("Error: bad input");
    t[0] = s.substr(0,4);
    t[1]= s.substr(5,2);
    t[2]=s.substr(8,2); 
   if((t[0]).find_first_not_of(tmp)!= std::string::npos || atoi(t[0].c_str()) <= 0 || atoi(t[0].c_str()) > 2023)
         throw std::runtime_error("Error: bad input");
    if((t[1]).find_first_not_of(tmp)!= std::string::npos || atoi(t[1].c_str()) <= 0 || atoi(t[1].c_str()) > 12)
        throw std::runtime_error("Error: bad input");
    if(atoi(t[1].c_str()) == 02)
    {
        if(isLeapYear(atoi(t[0].c_str())))
        {
            if(atoi(t[2].c_str()) > 29)
                throw std::runtime_error("leap year");
        }
        else
        {
            if(atoi(t[2].c_str()) > 29)
                throw std::runtime_error("not leapyear");
        }
    }
    if((t[2]).find_first_not_of(tmp)!= std::string::npos || atoi(t[2].c_str()) <= 0 || atoi(t[2].c_str()) > 31)
        throw std::runtime_error("bad * input");
    sDate = s;
    s = t[0]+t[1]+t[2];
    return(atoi(s.c_str()));
}
double BitcoinExchange:: valueFormat(std::string& str)
{

   if(str.find_first_not_of("0123456789.")!=std::string::npos )
        throw std::runtime_error("Error: not a positive number.");
    if(atof(str.c_str()) > 1000)
            throw std::runtime_error("Error: too large number.");
    return(atof(str.c_str()));
}

void BitcoinExchange:: CoinExchange(int date,double value)
{  
        std::map<int,double>::iterator it = myMap.lower_bound(date);
      
        if(it != myMap.end())
        { 
            if( it == myMap.begin() && it->first == date)
                std::cout<<sDate<< "=>"<<" "<<value<<" = " << it->second * value <<std::endl;
            else if(it != myMap.begin() && it->first == date )
                std::cout<<sDate<< "=>"<<" "<<value<<" = " << it->second * value <<std::endl;
            else if(it != myMap.begin())
               { --it;
                std::cout<<sDate<< "=>"<<" "<<value<<" = " <<it->second * value <<std::endl;
            }
            else
                std::cout<<sDate<< " not found \n";
        }
        else 
                std::cout<<sDate<<  " not found \n";
    
}