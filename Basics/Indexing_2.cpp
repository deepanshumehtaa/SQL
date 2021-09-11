invisible index in MySQL::

The invisible indexes allow you to mark indexes as unavailable for the query optimizer. 
MySQL maintains the invisible indexes and keeps them up to date when the data in the columns associated with the indexes changes (SUPEREB).

By default, indexes are visible.
  
# Eg1

CREATE INDEX index_name
ON table_name( c1, c2, ...) INVISIBLE;  

and to change the visibility

ALTER TABLE employees
ALTER INDEX index_name VISIBLE; 

"INFORMATION_SCHEMA" provides access to database metadata, information about the MySQL server such as 
name of a database or table, the data type of a column, or access privileges. 
  
  
  
  
  
  
  
  
  
  
  
  
