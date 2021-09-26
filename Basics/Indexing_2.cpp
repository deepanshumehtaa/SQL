This file covers:
1. Invisible Index
2. Clustered Index
3. MySQL Prefix Index
4. Removing Index

and Advanced Topics like:
USE INDEX hint –
FORCE INDEX hint 

invisible index::>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

The invisible indexes allow you to mark indexes as unavailable for the query optimizer. 
MySQL maintains the invisible indexes and keeps them up to date when the data in the columns associated with the indexes changes (SUPEREB).

> By default, indexes are visible.
>   The index on the primary key column cannot be invisible  
# Eg1

CREATE INDEX index_name
ON table_name( c1, c2, ...) INVISIBLE;  

and to change the visibility

ALTER TABLE employees
ALTER INDEX index_name VISIBLE; 

"INFORMATION_SCHEMA" provides access to database metadata, information about the MySQL server such as 
name of a database or table, the data type of a column, or access privileges. 
  
In Django::...................................

class Customer(models.Model):
    first_name = models.CharField(max_length=100)
    last_name = models.CharField(max_length=100)

    class Meta:
        indexes = [
            models.Index(fields=['last_name', 'first_name'], name='full_name_idx'),
            models.Index(fields=['first_name'], name='first_name_idx'),
        ]
 
Clustered index::>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
A clustered index is a special type of index that reorders the way records in the table are physically stored.
  
This is Reallyt Expensive and Complex better to avoid
  
  
MySQL Prefix Index::>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  When you create a secondary index for a column, MySQL stores the values of the columns in a separate data structure e.g., B-Tree and Hash.
  and this take large storage and makes the INSERT slow so, MySQL allows u to create an index for the leading part of the column values of the string columns using the following syntax:
  
  ==> column_name(length) : gives u the power to change the length of the index key
  Eg:
  
  CREATE TABLE table_name(
    column_list,
    INDEX(column_name(length))
  );

  
  and on existing table
  
  CREATE INDEX index_name
  ON table_name(column_name(length)); 













