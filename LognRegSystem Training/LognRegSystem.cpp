#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

const std::string refCode = "WASD1";


int main()
{   
    int lifeLeft = 0;
    std::string userId;
    std::string userPass;
    std::string adminId;
    std::string adminPass;    
    std::string infoName;   
    std::ifstream userFileR;
    std::ofstream userFileW;
    std::ifstream adminFileR;
    std::ofstream adminFileW;
    std::string confirm;
    
    
    int choice;
    do {
        
        std::cout << "1. Login " << std::endl << "2. Register "<<std::endl<<"3. Admin Login : "<<std::endl<<"4. Admin Reg : "<<"Select : ";
        std::cin >> choice;
        
    } while(choice>4||choice<1);

    if (choice == 1)
    {

        std::string str;
        std::string str2;
        std::string check = userId + " " + userPass;
        std::string info;

        do {
            std::cout << "User ID  : "; std::cin >> userId;
            userFileR.open("id.txt", std::ifstream::app);

            while (!userFileR.eof())
            {
                userFileR >> str;
                if (str == userId) {
                    std::cout << "AGA OLDU" << std::endl;
                    break;
                }

            }
            if (str != userId)
            {
                std::cout << "This ID not found! ";
                userFileR.close();
            }

        } while (str != userId);
        userFileR.close();


        do {
            std::cout << "User Pass  : "; std::cin >> userPass;
            check = userId + " " + userPass;

            userFileR.open("pass.txt", std::ifstream::app);
            while (getline(userFileR, str2))
            {


                if (check == str2)
                {
                    std::cout << "AGA OLDU" << std::endl;
                    break;
                }
            }
            if (check != str2)
            {
                std::cout << "This ID not found!" << std::endl;
                userFileR.close();
            }
        } while (str2 != (userId + " " + userPass));
        userFileR.close();


    }
    else if (choice == 2)
    {
        std::string idCheck;
        do {
            std::cout << "User ID : "; std::cin >> userId;
            if (userId.size() > 10) {
                std::cout << "FALSE ALARMMM";
            }
            userFileR.open("id.txt", std::ifstream::app);
           
            while (!userFileR.eof())
            {
                userFileR >> idCheck;
                if (idCheck == userId)
                {
                    std::cout << "This ID already exist! ";
                    userFileR.close();
                    break;
                }
            }
        } while (userId.size() > 10 || idCheck==userId);
        
       
        do {
            std::cout << "User Pass : "; std::cin >> userPass;
            if (userPass.size() > 10) {
                std::cout << "FALSE ALARMMM";
            }
            std::cout << "Confirm Pass : "; std::cin >> confirm;
            while (confirm != userPass)
            {
                std::cout << "Wrong Confirm! ";
                std::cout << "User Pass : "; std::cin >> userPass;
                std::cout << "Confirm Pass : "; std::cin >> confirm;
            }
        } while (userPass.size() > 10);
        userFileW.open("id.txt", std::ofstream::app);
        userFileW << userId << "\n";
        userFileW.close();

        userFileW.open("pass.txt", std::ofstream::app);
        userFileW << userId << " " << userPass << "\n";
        userFileW.close();
        std::cout << "Please Enter Your Name and Surname  :"; std::cin >> infoName;
        userFileW.open("infos.txt", std::ofstream::app);
        userFileW << userId << " " << infoName << "\n";
        userFileW.close();

        std::cout << std::endl;
        std::cout << "Registration Completed!";



    }
    else if (choice == 4 )
    {   
        std::string RefCheck;
        std::cout << "Please write Ref Code : "; std::cin >> RefCheck;
        if (refCode != RefCheck)
        {
            system("CLS");
            for (int i = 0; i < 5; i++) {
                std::cout << "You illegal thief!" << std::endl;
            }
            exit(0);
        }

        do {
            std::cout << "Admin ID : "; std::cin >> adminId;
            adminFileW.open("adminId.txt", std::ofstream::app);
            adminFileW << adminId << "\n";
            adminFileW.close();
            std::cout << std::endl;
            std::cout << "Admin Pass : "; std::cin >> adminPass;
            std::cout << "Confirm Pass : "; std::cin >> confirm;
            while (confirm != adminPass) {
                std::cout << "Wrong Confirmation! Please write again!";
                std::cout << "Admin Pass : "; std::cin >> adminPass;
                std::cout << "Confirm Pass : "; std::cin >> confirm;
            }
            adminFileW.open("adminPass.txt", std::ofstream::app);
            adminFileW << adminId << " " << adminPass;


        } while (false);
    }

    else if (choice == 3)
    {
        
        std::string str;
        std::string str2;
        std::string check = adminId + " " + adminPass;
        std::string info;

        do {
            std::cout << "Admin ID  : "; std::cin >> adminId;
            adminFileR.open("adminId.txt", std::ifstream::app);

            while (!adminFileR.eof())
            {
                adminFileR >> str;
                if (str == adminId) {
                    std::cout << "AGA OLDU" << std::endl;
                    break;
                }

            }
            if (str != adminId)
            {
                std::cout << "This ID not found! ";
                adminFileR.close();
            }

        } while (str != adminId);
        adminFileR.close();


        do {
            std::cout << "User Pass  : "; std::cin >> adminPass;
            check = adminId + " " + adminPass;

            adminFileR.open("adminPass.txt", std::ifstream::app);
            while (getline(adminFileR, str2))
            {
                if (check == str2)
                {
                    std::cout << "AGA OLDU" << std::endl;
                    break;
                }
            }
            if (check != str2)
            {
                std::cout << "This ID not found!" << std::endl;
                adminFileR.close();
            }
            lifeLeft++;
            if (lifeLeft == 3)
            {
                system("CLS");
                for (int i = 0; i < 5; i++)
                {
                    std::cout << "YOU FAILED ALREADY 3 TIMES YOU THIEF";                    
                }
                exit(0);
            }
        } while (str2 != (adminId + " " + adminPass));
        adminFileR.close();
        system("CLS");
        std::cout << "ALL INFORMATION ABOUT USERS.... " << std::endl << std::endl << std::endl;
        std::cout << "ID   Name";
        adminFileR.open("infos.txt", std::ifstream::app);
        std::string data;
        while (getline(adminFileR, data))
        {
            std::cout << data << std::endl;
        }

    }

}


