#SDatabase Class

Created By : Mohamed El Sayed


##Member functions :

**1- exists**

- Arguments :

    A string contains the id that you want to know if it exists or not
    
- Return type :

    `exists` returns a boolean value, `true` if the id exists. `false` if not
    


**2- createDB**

  - Arguments :
  
    A string with the name of the text file aka database you want to load
    
  **NOTE :** 

    `createDB` must be initialized in order to supply the class with the name of the database to process
    
  - Return type : 
      
    None


**3- addNew**

  - Arguments :
  
    `addNew` Has no direct arguments, it adds what stored in these variables `id`, `name`, `address` to the database so these variables must be initialized with a non-empty value

  - Return type : 
      
    `addNew` returns `true` if the addition successeded, `false` if any problem detected
    `addNew` will return false if any of the previous three variables empty or contains `;` or `%`


**4- searchById**

  - Arguments : 
  
    A string with the id that you want to search for
    
  - Return type :
  
    `searchById` returns `false` if the id is not exists or the database is empty, and returns `true` and prints out the row data if the id exists


**5- deleteById**

  - Arguments : 
  
    A string with the id of the row that you want to delete

  - Return type :
  
    `true` if the id detected and deleted, `false` if anything prevent deleting process like the database is empty or the id is not exists


**6- viewAll**

  - Arguments : 
    
    None

  - Return type : 
  
    `-1` if the database is empty, `1` and prints out the database content if not


**7- clear**

  - Arguments :
  
    None

  - Return type :
  
    None



##Member variables : 

**1- enable_duplication**

- If this variable = `false` you will get error when you try to add an existing id to the database set it to true to allow this process
    
    **enable_duplication = false by default**
    
**2- id, name, address**


- The value of this variables added to the database when `addNew` function is called
    
