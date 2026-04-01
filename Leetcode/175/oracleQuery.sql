SET PAGESIZE 100
SET LINESIZE 200

SELECT 
    p.firstName, 
    p.lastName, 
    a.city, 
    a.state
FROM Person p
LEFT JOIN Address a
ON p.personId = a.personId;

EXIT;

-- This query retrieves the first name and last name of persons along with their city and state from the Address table.
-- The LEFT JOIN ensures that all records from the Person table are included, even if there is no matching address record.
-- If a person does not have a corresponding address, the city and state will be NULL.
-- The query joins the Person table (aliased as P) and the Address table (aliased as A) on the personid field.
-- 'firstName', 'lastName', 'city', and 'state' are selected as output columns with appropriate aliases.