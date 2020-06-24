# work done today...............................................................
Hi everyone, 

Assessment Discussion Module 4 DBMS ( TOPICS: Data Independence, 
Three schema Architecture, Three tire architecture, file system vs DBMS )

# Databases with Python

The concept of unicode is to unite all the language, because before UTF-8, everyone(american, japanese) is using their own ASCII.
UTF-8 compatible with ASCII.

> for python2 "string" and "unicode string" are diffrent classes, but in python3 both are the same classes.

>Sir says "Object are like micro api", they talk



Various Data models: network datamodel, herirical datamodel, relational datamodel (RDBMS),
			     ER Model, object oriented datamodel.
ER Model ( attribute, Relationship, type of relationship (121, etc))
(Keys, primary key, candidate key, foreign key, super key)
(Normalization => closure method (no. of candidate keys), Normal form)

DBMS
SQL can execute queries against a database

# how DBMS superior than the file system
1. Attribute (storing location independet, we can access only with the help of quert)
2. Concurency  (many user try to access the same data, but there is no such protocol in the file system)
3.  Security ( there are diffrent "roles", which prevent the user to look for the sensitive info. ie. role base access control ) 
4. Avoid Redundancy

## 2 tire and 3 tire 	?
>Ans: 2 tire means 2 layer ( client layer and database server )   
[ This arch. fails when we have so many users  scalability, security amd Maintainace  ]

3 Tire (Application ( Client ) layer, Business Logic layer (BLL), Data layer )
[ BLL Application processing Coordinates data between the UI and DAL, also adds security by not direct interacting with dbms]

## what is schema of database?
> it is logical representation of database or simpli the structure of the data.

## Three Schema Architecture?
> Ans: The three schema architecture is also used to separate the user applications and physical database.
       The need for this arch. to prevent the user to access or interact directly with the database. basicaal this is Data abstraction.
       [External schema, conceptual schema, internal schema]      
1.     External schema (view level): how we are going to show the data to the user. ( front end )
       
2.     conceptual Schema: what is the structure of the database also hide it from user. 
       				ie. ER model. relationship how table are connected. ( Blue Print )
3.     Internal schema (Physical level): Disk storage. ( DB administrator )
       Mapping is used to transform the request and response between various database levels of architecture.
       
## what is "Data Independence in DBMS"?	
Ans: Data Independence helps you to change the Database schema at one level of a database system "without requiring to change the schema at the next level". Data independence helps you to keep data separated from all programs that make use of it.

Types:
1. Physical data independence: when we need to to change physical schema without in the change of higher level ( Conceptual level) schema
2. Logical data independence: when we need to to change conceptual schema without in the change of higher level (application progreme) schema

## What is Data Model?
> Ans: Data Model is the modeling of the data description, data semantics, and consistency constraints of the data. 
	 It provides the conceptual tools which help you to imagine the design of a database at each level of data abstraction.
	 ( just the perception but the physical storage in dbms could directly be diffrent )
	 (what if all these are dependent, them change in physical level results in change in the view level, means everytime i change dbms structure
	  results into the diffrent look of my application, "" har bar user ko diffrent application milegi "" )
	 
	 4 Models
	 
	 1. Relational Data Model: This type of model designs the data in the form of rows and columns within a table. 
	 				  Thus, a relational model uses tables for representing data and in-between relationships. 
	 				  Tables are also called relations.
	 				  
	 2. Entity-Relationship Data Model: An ER model is the logical representation of data as objects and relationships among them. 
	 					     These objects are known as entities, and relationship is an association among these entities.     
	 					
	 3. Object-based Data Model:	An extension of the ER model with notions of functions, encapsulation, and object identity, as well. 
	 					This model supports a rich type system that includes structured and collection types.				
         
         4. Semistructured Data Model:  XML, is widely used for representing the semistructured data.
         
## Some Definations
> **Entities** are the principal data objects about which information is to be collected. (simply a table, but not a table )

> **Relationships** represent real-world associations among one or more entities, and as such, have no physical or conceptual existence other than that which 
     depends upon their entity associations. Relationships are described in terms of degree, connectivity, and existence.
     The meaning associated with the term relationship is indicated by the connectivity between entity occurrences: one-to-one, oneto-many, and many-to-many. 
     The relationship construct is "a diamond". 

>**Attributes** are characteristics of entities that provide descriptive detail about them, Attributes of an entity such as 
		   Employee may include emp-id, emp-name, emp-address, phone-no, fax-no, job-title, etc.
		   
		   There are 2 type of "Identifiers" and "Descriptors"
		   1. **An identifier (or key)** is used to uniquely determine an instance of an entity. For example, an identifier or key of
		       Employee is emp-id
		   2. **A descriptor (or nonkey attribute)** is used to specify a nonunique characteristic of a particular entity instance. 
		   	For example, a descriptor of Employee might be emp-name or job-title; 
		   	
## Keys
> key (Attribute): A DBMS key is an attribute or set of an attribute which helps you to identify a row(tuple) in a relation(table). 
		     They allow you to find the relation between two tables. Keys help you uniquely identify a row in a table by 
		     a combination of one or more columns in that table.
		     	
** Various Keys in Database Management System**
         Super Key
         Primary Key
	Candidate Key
	Alternate Key
	Foreign Key
	Compound Key
	Composite Key
	Surrogate Key
	
## What is the Super key?
> A superkey is a group of single or multiple keys which identifies rows in a table. A Super key may have additional attributes that are not needed for unique
   identification.

## What is a Primary Key?											
>  that uniquely identify every row in that table. The Primary Key can't be a duplicate meaning the same value 
    can't appear more than once in the table. A table cannot have more than one primary key.
    Also, The primary key field cannot be null.
    	   The value in a primary key column can never be modified or updated if any foreign key refers to that primary key.
    
## Alternative keys?
> A table can have multiple choices for a primary key but only one can be set as the primary key. 
   All the keys which are not primary key are called an Alternate Key.
   Ex.
   	In this table, StudID, Roll No, Email are qualified to become a primary key. 
   	But since StudID is the primary key, Roll No, Email becomes the alternative key.

## Candidate Key? 
> CANDIDATE KEY is a set of attributes that uniquely identify tuples in a table. Candidate Key is a super key with no repeated attributes. 
   The Primary key should be selected from the candidate keys. Every table must have at least a single candidate key. 
   A table can have multiple candidate keys but only a single primary key.
   
   Properties of Candidate key:
   
>  It must contain unique values
   Candidate key may have multiple attributes
   Must not contain null values
   it should contain minimum fields to ensure uniqueness
   Uniquely identify each record in a table

Example: In the given table Stud ID, Roll No, and email are candidate keys which help us to uniquely identify the student record in the table.

## FOREIGN KEY is a column that creates a relationship between two tables.
>

## What is the Compound key?	
>  COMPOUND KEY has two or more attributes that allow you to uniquely recognize a specific record. 
    It is possible that each column may not be unique by itself within the database. However, when combined with the other column or columns 
    the combination of composite keys become unique. The purpose of compound key is to uniquely identify each record in the table.

##
>
