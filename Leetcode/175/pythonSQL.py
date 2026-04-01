import pandas as pd

# ---------------------------
# SQL Server Connection
# ---------------------------
import pyodbc

print("Connecting to SQL Server...")

sql_conn = pyodbc.connect(
    "DRIVER={ODBC Driver 18 for SQL Server};"
    "SERVER=localhost,1433;"
    "DATABASE=master;"
    "UID=sa;"
    "PWD=Strong@123Password;"
    "TrustServerCertificate=yes;"
)

sql_query = """
SELECT p.firstName, p.lastName, a.city, a.state
FROM Person p
LEFT JOIN Address a
ON p.personId = a.personId;
"""

sql_df = pd.read_sql(sql_query, sql_conn)

print("\n--- SQL Server Result ---")
print(sql_df)


# ---------------------------
# Oracle Connection
# ---------------------------
import oracledb

print("\nConnecting to Oracle...")

oracle_conn = oracledb.connect(
    user="system",
    password="Oracle123",
    dsn="localhost:1521/XEPDB1"
)

oracle_query = """
SELECT p.firstName, p.lastName, a.city, a.state
FROM PERSON p
LEFT JOIN ADDRESS a
ON p.personId = a.personId
"""

oracle_df = pd.read_sql(oracle_query, oracle_conn)

print("\n--- Oracle Result ---")
print(oracle_df)