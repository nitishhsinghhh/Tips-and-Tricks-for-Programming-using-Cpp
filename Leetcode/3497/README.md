# SQL Test in VS Code

## Files

- `setup.sql` → creates table and inserts sample data
- `query.sql` → runs the required query

## How to test in VS Code

1. Install the **SQL Server (mssql)** extension.
2. Open VS Code.
3. Open this folder.
4. Connect to SQL Server using:
   - `Ctrl + Shift + P`
   - Search: `MS SQL: Connect`
5. Run `setup.sql` first.
6. Run `query.sql` after that.

## Expected Output

```text
user_id | trial_avg_duration | paid_avg_duration
1       | 37.50              | 75.00
2       | 20.00              | 40.00