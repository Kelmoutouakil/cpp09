/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmouto <kelmouto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:08:00 by kelmouto          #+#    #+#             */
/*   Updated: 2023/12/12 14:16:48 by kelmouto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac,char *av[])
{
    std::string s;
    RPN o;

    try
    {
         if(ac == 2)
        {
            s = av[1];
            if(s.find("(") == std::string::npos)
            {
               std::cout<< o.splitInput(s)<< std::endl;
            }
            else
                throw std::runtime_error("Error");
        
        }
        else
            throw std::invalid_argument(" invaliid argument");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   
}