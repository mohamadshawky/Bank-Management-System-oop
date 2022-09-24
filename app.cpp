/********************************************************************************************************************************************
Author: 	 Mohamed Shawky Ahmed
Description: Bank Management System - C++ based-OOP console project providing some admin and user commands.
Version:     01
file:        app.cpp
Date:        31/08/2022
*********************************************************************************************************************************************/
#include "include/STD_TYPES.h"

#include <iostream>
#include <stdlib.h>
#include <string>

#include "include/cClient.h"
#include "include/cAdmin.h"

extern u32 clients_size;
extern cClient clients[50];
extern u32 admins_size;
extern cAdmin admins[50];

cClient user;
cAdmin admin;

/* Global functions */

/* This function checks on client password */ 
u32 get_client_pwd(u32 pwd){
		for (u32 i = 0; i < clients_size; i++){				
		if (clients[i].get_account_password() == pwd){
			return clients[i].get_account_password();}
	}
	return 0;
}

/* This function checks on client password */ 
u32 get_admin_pwd(u32 pwd){
		for (u32 i = 0; i < clients_size; i++){				
		if (admins[i].get_account_password() == pwd){
			return admins[i].get_account_password();}
	}
	return 0;
}


int main(){
	
	system ("cls");
	
	u32 mode = 0;	
	u8 count = 0;

	BEGINNING:

	std::cout << " 0: USER MODE "  << std::endl
			  << " 1: ADMIN MODE " << std::endl
			  << " 2: EXIT "       << std::endl;
			  
	std::cout << " COMMAND:   \t";
	std::cin >> mode;
	
	switch(mode){	
	
		case 0:{	//user mode		
		
			u32 command, id, old_pwd, new_pwd;
			s64 balance;
			
			system("cls");
			CLIENTMODDE:
			std::cout << "********* WELCOME TO BANK MANAGEMENT SYSTEM *********" << std::endl;
			std::cout << " 1: CREATE A NEW USER ACCOUNT"						 << std::endl;
			std::cout << " 2: MAKE TRANSFER"									 << std::endl;
			std::cout << " 3: CHANGE ACCOUNT PASSWORD " 					     << std::endl;
			std::cout << " 4: GET CASH " 										 << std::endl;
			std::cout << " 5: DEPOSIT IN ACCOUNT "								 << std::endl;
			std::cout << "-1: BACK " 											 << std::endl;
			std::cout << " 0: EXIT "                                             << std::endl;
			std::cout << "*****************************************************" << std::endl;
			
			std::cout << " COMMAND:\t";
			std::cin >> command;
			
			switch(command){
				
				case -1: {
					system("cls");
					return 0;
					break;
				}
				
				case 0:{
					exit(1);
					break;
				}	
				
				case 1:{
					count = 0;
					CLIENTSNUMBER:
					
					if (count == 3){
						std::cout << "\n No more tries!" << std::endl;
						return 0;}
						
						std::cout << " NUMBER OF CLIENTS = \t";
						std::cin  >> clients_size;
						
					if (clients_size >= 50 || clients_size <= 0){
						std::cout << "\n Enter size within 1-50!"<< std::endl;
						++count;
						goto CLIENTSNUMBER;}
						
					for (u32 i = 0; i < clients_size; i++){clients[i].create_account();}
						std::cout << std::endl
								  << clients_size 
								  <<" USERS ACCOUNTS ARE CREATED SUCCESSFULLY..." 
								  << std::endl;	 
								  
					command = 0;
					goto CLIENTMODDE;
					break;	
				}	
					
				case 2:{
					count =0;		
					USERID:
					
					if(count == 3){
						std::cout << "\n No more tries!\n";
						return 0;}
						
					std::cout << " ACCOUNT ID: \t";
					std::cin >> id;
					
					if ((id < MIN10DIGITS) || (id > MAX10DIGITS)){
						++count;
						std::cout << "\n Try again!" <<std::endl;
						goto USERID;}
						
					std::cout << " BALANCE = \t\t";
					std::cin >> balance;
					
					user.make_transaction(id, balance);
					command = 0;
					goto CLIENTMODDE;	
					break;	
				}
				
				case 3:{
					std::cout << " OLD PASSWORD: \t";
					std::cin >> old_pwd;
					
					std::cout << " NEW PASSWORD: \t";
					std::cin >> new_pwd;
					
					user.change_account_pwd(old_pwd, new_pwd);
					command = 0;
					goto CLIENTMODDE;
					break;
				}	
				
				case 4:{
					std::cout << " BALANCE = \t";
					std::cin >> balance;
					
					user.withdraw(balance);
					
					command = 0;
					goto CLIENTMODDE;
					break;
				}
					
				case 5:{
					std::cout << " BALANCE = \t";
					std::cin >> balance;
					
					user.deposit(balance);
					command = 0;
					goto CLIENTMODDE;						
					break;
				}				
				default:{
					std::cout << "\n Invalid Input!";
					command = 0;
					goto CLIENTMODDE;
				}				
			}//end of user switch body									
				break;
		} // end of CASE 0 body	
		
		case 1:{	//admin mode
		
			system("cls");
									
			ADMINMODE:
			std::cout << "********* WELCOME TO BANK MANAGEMENT SYSTEM *********"<< std::endl;
			std::cout << " 1: CREATE A NEW ADMIN ACCOUNT"  					    << std::endl;
			std::cout << " 2: MAKE TRANSFER"	    						    << std::endl;
			std::cout << " 3: CHANGE ACCOUNT STATUS"                            << std::endl;
			std::cout << " 4: Get CASH"										    << std::endl;
			std::cout << " 5: DEPOSIT IN ACCOUNT"                               << std::endl;
			std::cout << "-1: BACK"											    << std::endl;
			std::cout << " 0: EXIT"												<< std::endl;
			std::cout << "*****************************************************"<< std::endl;
			
			u32 command, id;
			u64 balance;
			std::string status;
			u8 count = 0;						
			
			std::cout << " COMMAND:\t";
			std::cin  >> command;
			
			system("cls");
			switch(command){
				
				case -1: {
					system("cls");
					return 0;
					break;
				}
				
				case 0:{	
					exit(1);
					break;
				}	
				
				case 1:{
					count = 0;
					u32 id;
					ADMINSNUMBER:
					
					if (count == 3){
						std::cout << "\n No more tries!" << std::endl;
						return 0;}
						
					std::cout << " NUMBER OF ADMINS = \t";
					std::cin  >> admins_size;
					
					if (admins_size >= 50 || admins_size <= 0){
						std::cout << "\n Enter size within 1-50!"<< std::endl;
						++count;
						goto ADMINSNUMBER;}
						
					for (u32 i = 0; i < admins_size; i++){admins[i].create_account();}
					std::cout << std::endl
							  << admins_size 
							  <<" ADMINS ACCOUNTS ARE CREATED SUCCESSFULLY..." 
							  << std::endl;	
							  
					command = 0;
					goto ADMINMODE;
					break;
				}
					
				case 2:	{	
					count = 0;					
					ID:
					if(count == 3){
						std::cout << "\n>>No more tries!" << std::endl;
						return 0;
					}	
					std::cout << " ACCOUNT ID : \t";
					std::cin >> id;
					
					if ((id < MIN10DIGITS) || (id > MAX10DIGITS)){
						std::cout << "\n>> Try again!" << std::endl;
						++count;
						goto ID;
					}	
					std::cout << " BALANCE = \t";
					std::cin >> balance;
					
					admin.make_transaction(id, balance);
					command = 0;
					goto ADMINMODE;
					break;
					}		
					
				case 3:{
					std::cout << " STATUS:  \t";
					std::cin.ignore();
					getline(std::cin, status);	
					admin.change_account_status(status);
					command = 0;
					goto ADMINMODE;
					break;
				}	
				
				case 4:{
					std::cout << " BALANCE = \t";
					std::cin >> balance;
					admin.withdraw(balance);
					command = 0;
					goto ADMINMODE;
					break;
				}						
				
				case 5:{
					std::cout << " BALANCE = \t";
					std::cin >> balance;
					admin.cClient::deposit(balance);
					command = 0;
					goto ADMINMODE;
					break;
				}	
				
				default:{
					std:: cout << "\n Invalid Input!";
					command = 0;
					goto ADMINMODE;}					
				} //end of admin switch body
				
				break;
				} //end of case 1 body
			
				case 2:{	//exit from user or admin
					exit(1);
					break;
				}
				
		default:{
			std::cout << "\n Invalid input!" << std::endl;
			mode = 0;
			goto BEGINNING;			
		}
	}			
}
