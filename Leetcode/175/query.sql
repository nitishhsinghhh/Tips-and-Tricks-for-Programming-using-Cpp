/* Write your T-SQL query statement below */

/* 
    SQL Query: Retrieve all persons and their address information (if available). 
    The query uses a LEFT JOIN to ensure all persons are included, even if they have no address data.
*/

/* 
    INNER JOIN: Combines rows from two tables where there is a match in the specified columns. 
                Use it when you need data that exists in both tables.
    OUTER JOIN: Includes rows even if there is no match. Missing values are filled with NULL.
    LEFT OUTER JOIN (LEFT JOIN): Ensures all rows from the left table are included. 
                                 Rows from the right table are included where a match is found, otherwise NULL is returned for missing matches.
    RIGHT OUTER JOIN (RIGHT JOIN): Includes all rows from the right table, with matches from the left table.
*/

SELECT 
    P.firstName AS FirstName,  -- Retrieves the person's first name.
    P.lastName AS LastName,    -- Retrieves the person's last name.
    A.city AS City,            -- Retrieves the city from the address table. NULL if no match.
    A.state AS State           -- Retrieves the state from the address table. NULL if no match.
FROM 
    Person P                   -- Primary table containing personal information.
LEFT JOIN 
    Address A                  -- Secondary table containing address information.
ON 
    P.personid = A.personid;   -- Join condition: Matches persons to their address based on person ID.

/* 
    Explanation of Logic:
    - The query uses a LEFT JOIN because we want to include all rows from the `Person` table, 
      even if no matching rows exist in the `Address` table.
    - If a person does not have an address in the `Address` table, the `City` and `State` columns
      will return NULL for that person.
    - This is useful when the `Person` table is the main focus of the query, 
      and address data is optional or secondary.
*/