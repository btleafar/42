/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 10:03:30 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/06 10:03:31 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int
main(int argc, char const *argv[])
{
    std::string         s1;
    std::string         s2;
    std::string         buffer;
    std::string         output;
    std::string         filename;

    if (argc == 4)
    {
        s1 = argv[2];
        s2 = argv[3];
        filename = argv[1];
        output = filename + ".replace";
        std::ifstream   readFile(filename);
        if (readFile.fail())
        {
            std::cout << "Error opening file! :(" << std::endl;
            exit(1);
        }
        std::ofstream    outFile(output);
        if (outFile.fail())
        {
            std::cout << "Error creating file! :(" << std::endl;
            exit(1);
        }
        while (std::getline(readFile, buffer))
        {
            while (buffer.find(s1) != std::string::npos)
            {
                buffer.replace(buffer.find(s1), s1.length(), s2);
            }
            outFile << buffer;
            outFile << std::endl;
        }
        if (buffer == "")
        {
            outFile << std::endl;
        }
        readFile.close();
        outFile.close();
    }
    else
    {
        std::cout << "usage: " << argv[0];
        std::cout << " file <string_1> <string_2>" << std::endl;
    }
    return (0);
}
