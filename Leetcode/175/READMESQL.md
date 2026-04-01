# SQL Server Docker Setup + Run SQL Files (Step-by-Step Guide)

## PART 1: SQL Server Setup

## 1. Open Docker Desktop

* Start **Docker Desktop** on your system
* Wait until it shows **Docker is running**

---

## 2. Check Existing Containers

Open terminal in VS Code or Mac terminal:

```bash
docker ps -a
```

### If you see any old SQL Server container

Example:

```bash
elegant_dijkstra
```

Remove it:

```bash
docker rm elegant_dijkstra
```

---

## 3. Create New SQL Server Container

```bash
docker run -e "ACCEPT_EULA=Y" \
-e "SA_PASSWORD=Strong@123Password" \
-p 1433:1433 \
--name sqlserver-test \
-d mcr.microsoft.com/mssql/server:2022-latest
```

---

## 4. Verify Container is Running

```bash
docker ps
```

You should see:

```bash
sqlserver-test   Up ...
```

---

## 5. Run `setup.sql`

```bash
docker exec -i sqlserver-test /opt/mssql-tools18/bin/sqlcmd \
-S localhost -U sa -P "Strong@123Password" \
-d master -C < setup.sql
```

---

## 6. Run `query.sql`

```bash
docker exec -i sqlserver-test /opt/mssql-tools18/bin/sqlcmd \
-S localhost -U sa -P "Strong@123Password" \
-d master -C < query.sql
```

---

## 7. (Optional) Verify Data

```bash
docker exec -it sqlserver-test /opt/mssql-tools18/bin/sqlcmd \
-S localhost -U sa -P "Strong@123Password" -C
```

## Common Issues & Fixes

### sqlcmd not found

Use:

```bash
/opt/mssql-tools18/bin/sqlcmd
```

### SSL error

Add:

```bash
-C
```

### Container exits immediately

Make sure:

* `ACCEPT_EULA=Y`
* Strong password used

---

## Final Workflow

1. Open Docker Desktop
2. Remove old container
3. Create new SQL Server container
4. Run `setup.sql`
5. Run `query.sql`

---

## Result

* SQL Server running in Docker
* Tables created
* Data inserted
* Queries executed successfully

---

You can now connect this database to:

* VS Code SQL extension
* Backend (C++, Python, etc.)
* Or run more queries easily

---

## PART 2: Oracle Setup

## 1. Remove Old Oracle Container (if exists)

docker rm oracle-test

## 2. Create Oracle Container

docker run -d \
-p 1521:1521 \
-e ORACLE_PASSWORD=Oracle123 \
--name oracle-test \
gvenzl/oracle-xe

## 3. Verify Container

```bash
docker ps
```

## 4. Wait for Oracle to Start

```bash
docker logs -f oracle-test
```

Wait until:

```bash
DATABASE IS READY TO USE!
```

## 5. Run oracleSetup.sql

```bash
docker exec -i oracle-test sqlplus system/Oracle123@localhost:1521/XEPDB1 \
< oracleSetup.sql
```

## 6. Run oracleQuery.sql

```bash
docker exec -i oracle-test sqlplus system/Oracle123@localhost:1521/XEPDB1 \
< oracleQuery.sql
```

## 7. Verify Tables (Important)

```bash
docker exec -it oracle-test sqlplus system/Oracle123@localhost:1521/XEPDB1
```

```bash
SELECT table_name FROM user_tables;
```

## Step 3: How to Run Your `.py` File (Pandas) in VS Code

---

### 1. Open Terminal in Visual Studio Code

Shortcut:

```bash
Cmd + `
```

---

### 2. Activate Virtual Environment (if using)

```bash
source venv/bin/activate
```

You should see:

```bash
(venv)
```

---

### 3. Make Sure pandas is Installed

```bash
pip install pandas
```

---

### 4. Navigate to Your File Location

```bash
pwd
ls
```

Ensure your file (e.g. `combine_tables.py`) is visible

---

### ▶️ 5. Run the Python File

```bash
python3 combine_tables.py
```

---

### Output

You will see result printed in terminal:

```bash
firstName lastName city state
...
```

---

### Common Errors

#### pandas not found

```bash
pip install pandas
```

---

#### Wrong file name (IMPORTANT)

Do NOT name file:

```bash
pandas.py 
```

Use:

```bash
combine_tables.py 
```

---

#### Python not found

```bash
python3 combine_tables.py
```

### Summary

1. Open terminal
2. Activate venv
3. Install pandas
4. Run file using `python3 filename.py`

---

Now your Pandas code will run correctly inside VS Code

## Step 4: How to Run Your .py File (Pandas + SQL/Oracle) in VS Code

### 1. Open Terminal in Visual Studio Code & Activate Virtual Environment

```Bash
Cmd + `
source venv/bin/activate
```

### 2. Install Required Packages

```Bash
pip install pandas pyodbc oracledb sqlalchemy
```

Note:
    - Make sure your ODBC Driver for SQL Server is installed (e.g., msodbcsql18)
    - Make sure Oracle Instant Client is available for oracledb.

### 4. Ensure SQL Server & Oracle Containers Are Running

```Bash
docker ps

/*
    SQL Server: localhost:1433
    Oracle XE: localhost:1521
*/
```

### 5. Naviagte to your file & run

```Bash
cd path/to/your/file
python3 pyhtonSQL.py
```

### 6. Expected Output

```Bash
Connecting to SQL Server...
--- SQL Server Result ---
  firstName lastName           city     state
0     ALLEN     WANG            NaN       NaN
1       BOB    ALICE  New York City  New York

Connecting to Oracle...
--- Oracle Result ---
  FIRSTNAME LASTNAME           CITY     STATE
0       BOB    ALICE  New York City  New York
1     ALLEN     WANG            NaN       NaN
```
