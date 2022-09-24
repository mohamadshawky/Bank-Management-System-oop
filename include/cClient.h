/********************************************************************************************************************************************
Author: 	 Mohamed Shawky Ahmed
Description: Bank Management System - C++ based-OOP console project providing some admin and user commands.
Version:     01
file:        cClient.h
Date:        31/08/2022
*********************************************************************************************************************************************/

#ifndef _CCIENT_H
#define _CCIENT_H

#include "STD_TYPES.h"

/* Verification data for national id & password */
#define MIN14DIGITS 	10000000000000		
#define MAX14DIGITS 	99999999999999
#define MIN10DIGITS 	1000000000
#define MAX10DIGITS 	9999999999	
#define MIN5DIGITS 		10000	
#define MAX5DIGITS 		99999
#define MIN3DIGITS		100
#define MAX3DIGITS		999

class cClient{
	
	private:
		u64 m_national_id;		
		u64 m_guardian_national_id;
		std::string m_name;
		std::string m_addr;
		f32 m_age;
		u32 m_acc_id;				
		u32 m_acc_pwd;				
		std::string m_acc_status;
		u64 m_acc_balance;
		
	public:
	
		/* Utilities functions */
		void change_acc_status(std::string);
		void add_acc_balance(u64);
		void sub_acc_balance(u64);
		
		/* APIs */
		cClient();
		void create_account();
		void make_transaction(u32, u64);
		void deposit(u64);
		void withdraw(u64);
		u32 change_account_pwd(u32, u32);
		
		/* Setter methods */
		void set_national_id(u64 national_id){m_national_id = national_id;}
		void set_guardian_national_id(u64 guardian_national_id){m_guardian_national_id = guardian_national_id;}
		void set_name(std::string name){m_name = name;}
		void set_address(std::string address){m_addr = address;}
		void set_age(f32 age){m_age = age;}
		void set_account_id(u32 account_id){m_acc_id = account_id;}
		void set_account_password(u32 account_password){m_acc_pwd = account_password;}
		void set_account_status(std::string account_status){m_acc_status = account_status;}
		void set_account_balance(s64 account_balance){m_acc_balance = account_balance;}
		
		/* Getter methods */
		u64 get_national_id(){return m_national_id;}
		u64 get_guardian_national_id(){return m_guardian_national_id;}
		std::string get_name(){return m_name;}
		std::string get_address(){return m_addr;}
		f32 get_age(){return m_age;}
		u32 get_account_id(){return m_acc_id;}
		u32 get_account_password(){return m_acc_pwd;}
		std::string get_account_status(){return m_acc_status;}
		u64 get_account_balance(){return m_acc_balance;}

};


/* This function return specified client if exists using id */ 
cClient& get_client(u32 id);


#endif /* _CCIENT_H */