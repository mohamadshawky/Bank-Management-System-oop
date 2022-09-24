/********************************************************************************************************************************************
Author: 	 Mohamed Shawky Ahmed
Description: Bank Management System - C++ based-OOP console project providing some admin and user commands.
Version:     01
file:        cClient.cpp
Date:        31/08/2022
*********************************************************************************************************************************************/

#include "../include/STD_TYPES.h"

#include <iostream>
#include <string>

#include "../include/cClient.h"
#include "time.h"

/* Global data */
cClient clients[50];
u32 clients_size;


cClient::cClient():
		m_national_id(0),
		m_guardian_national_id(0),
		m_name(""),
		m_addr(""),
		m_age(0),
		m_acc_id(0),
		m_acc_pwd(0),
		m_acc_status(""),
		m_acc_balance(0)	
		{}


/* This method change status of an object */
void cClient::change_acc_status(std::string str){m_acc_status = str;}

/* This method add balance to an object */
void cClient::add_acc_balance(u64 balance){m_acc_balance += balance;}
	
/* This method subtract balance from an object */
void cClient::sub_acc_balance(u64 balance){m_acc_balance -= balance;}

/* This function inputs personal data of the client like:
national ID, guardian national id, name, address, age,
account ID, password, status & balance. */
void cClient::create_account(){
	
	std::cout << "********** PERSONAL DATA *************\n";
	
	//enter national id
	u64 nat_id = 0;
	std::cout << " NATIONAL ID: \t\t";
	std::cin.ignore();
	std::cin >> nat_id;
	set_national_id(nat_id);

	//enter name
	std::string name = " ";
	std::cout << " FULL NAME:  \t\t";
	std::cin.ignore();
	std::getline(std::cin, name);
	set_name(name);

	//generate password																								
	srand(time(NULL)); 
	set_account_password(rand());	

	//enter address
	std::string addr = " ";	
	std::cout <<" FULL ADDRESS:\t\t";
	std::getline (std::cin,addr);
	set_address(addr);

	//account status
	set_account_status("active");

	//enter age
	f32 age = 0;
	u64 guardian_nat_id = 0;
	std::cout << " AGE:\t\t\t" ;
	std::cin >> age;
	set_age(age);

	//enter guardian national id 
	if (get_age() < 21){
		std::cout << " GUARDIAN NATIONAL ID: \t";
		std::cin >> guardian_nat_id;
		set_guardian_national_id(guardian_nat_id);}
	else {set_guardian_national_id(0x00);}

	//enter balance
	u64 bal = 0;
	std::cout << " ACCOUNT BALANCE: \t";
	std::cin >> bal;
	set_account_balance(bal);
	
	//assign account id
	static u32 temp_acc_id;
	temp_acc_id = 1000000000;
	set_account_id(temp_acc_id);	
	temp_acc_id++;

	// Display created account data 
	std::cout << "\n********** CREATED ACOOUNT SUCCESSFULLY ***********"<< std::endl;
	std::cout << " FULL NAME:  \t\t"    << get_name() 		  		    << std::endl;
	std::cout << " NATIONAL ID: \t\t"   << get_national_id()            << std::endl;
	std::cout << " FULL ADDRESS:\t\t"   << get_address()                << std::endl;
	std::cout << " AGE:\t\t\t" 		    << get_age()                    << std::endl;
	std::cout << " GUARDIAN NAT ID: \t" << get_guardian_national_id()   << std::endl;
	std::cout << " ACCOUNT ID:  \t\t"   << get_account_id()             << std::endl;
	std::cout << " ACCOUNT STATUS:  \t" << get_account_status()         << std::endl;
	std::cout << " ACCOUNT BALANCE: \t" << get_account_balance() << "$" << std::endl;   
	std::cout << " PASSWORD: \t\t"      << get_account_id()             << std::endl;

}

/* This function inputs account id 1, account id 2 & balance to transfer */
void cClient::make_transaction(u32 id, u64 balance){
	cClient client = get_client(id);
	if ((m_acc_status == "active") && (client.get_account_status() == "active") && (balance <= m_acc_balance)){
		m_acc_balance -= balance;
		client.add_acc_balance(balance);
		std::cout << " Account ID "<< id <<" balance = " << client.get_account_balance() << std::endl;
		std::cout << " Account ID "<<  get_account_id() <<" balance = " << get_account_balance() << std::endl;
	}
	else{
		std::cout << " Sorry! "
				  << std::endl
				  << " Account ID "
				  << get_account_id() 
				  << " has not sufficient balance or "
				  << " any of account ID "
				  << get_account_id()  
				  << " or ID " 
				  << id 
				  << " is not active."
				  << std::endl;
	 }

}

/* This function deposit balance of an account */
void cClient::deposit(u64 balance){		
	if (get_account_status() == "active"){
		add_acc_balance(balance);
		std::cout << " Account " 
				  << get_account_id() 
				  << " balance = " 
				  << get_account_balance();
	}
	else {
		std::cout << " Account ID "
				  << get_account_id() 
				  << " is not active! "
				  << std::endl;}
}

/* This function withdraw balance of an account*/
void cClient::withdraw(u64 balance){
	if ((get_account_status() == "active") && (balance <= get_account_balance())){
		add_acc_balance(balance);
		std::cout << " Account " 
				  << get_account_id()
				  << " balance = "
				  << get_account_balance()
				  << std::endl;
	}
	else {
		std::cout << " Account " 
				  << get_account_id() 
				  << " is not active or entered balance > account balance! "
				  << std::endl;
	}	
}

/* This function changes password of an account */		
u32 cClient::change_account_pwd(u32 old_pwd, u32 new_pwd){
	if (m_acc_status == "active"){
		if (old_pwd == m_acc_pwd){
			set_account_password(new_pwd);
			std::cout << " NEW PASSWORD FOR ACCOUNT " 
					  << get_account_id() 
					  << ":"
					  << get_account_password()
					  << std::endl;			
		}
		else{
			std::cout << " Password is not correct, Try again " << std::endl;}
	}
	else{
		std::cout << " Account ID "
				  << get_account_id()  
				  << "is not active!" 
				  << std::endl;
	}
}

cClient& get_client(u32 id){
	for (u32 i = 0; i < clients_size; i++){				
		if (clients[i].get_account_id() == id){
			return clients[i];}
	}
}
	