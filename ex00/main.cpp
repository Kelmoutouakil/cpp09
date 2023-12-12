/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:46:49 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/07 09:44:25 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac,char *av[])
{
    try
    {
        BitcoinExchange o;
        o.StoreMap();
        if(ac == 2)
        {
            std::string filename = av[1];
            std::string line;
            std::ifstream inputFile;
            inputFile.open(filename);
            if (!inputFile.is_open()) 
               throw std::invalid_argument("Error: could not open file") ;
            if (getline(inputFile, line)) 
            {
                if (line.find("date | value") != std::string::npos) 
                {
                    while (getline(inputFile, line)) 
                    {
                        try
                        {
                            std::string s;
                            std::string str;
                            int i = 0;
                            size_t delimiterPos = line.find('|');
                            if (delimiterPos == std::string::npos) 
                                throw std::invalid_argument("Error: bad input => "+ line);
                            while(line[i] != '|' && line[i] != '\0')
                                i++;
                            s = line.substr(0,i);
                            str = line.substr(i+2,line.length() - (i + 2));
                            int date = o.dateFormat(s);
                            double value = o.valueFormat(str);
                            o.CoinExchange(date,value);
                        }
                        catch(const std::exception& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                    }
                }
                else 
                    throw std::invalid_argument("header file error") ;
            }
             inputFile.close();
        }
        else
            throw std::invalid_argument("Error: could not open file.");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
 
 

