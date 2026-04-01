IF OBJECT_ID('Person', 'U') IS NOT NULL
    DROP TABLE Person;
GO

CREATE TABLE Person (
    personId INT,
    lastName VARCHAR(50),
    firstName VARCHAR(50)
);

GO

IF OBJECT_ID('Address', 'U') IS NOT NULL
    DROP TABLE Address;
GO   

CREATE TABLE Address (
    addressId INT,
    personId INT,
    city VARCHAR(50),
    state VARCHAR(50)
);

GO

INSERT INTO Person (personId, lastName, firstName) VALUES
(1, 'WANG', 'ALLEN'),
(2, 'ALICE', 'BOB');
GO

INSERT INTO Address (addressId, personId, city, state) VALUES
(1, 2, 'New York City', 'New York'),
(2, 3, 'Leetcode', 'California');
GO