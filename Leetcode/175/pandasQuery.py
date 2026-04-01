# Run commands:
# python3 combine_tables.py

import pandas as pd

# Sample data
person_data = [
    [1, 'Wang', 'Allen'],
    [2, 'Alice', 'Bob']
]

address_data = [
    [1, 2, 'New York City', 'New York'],
    [2, 3, 'Leetcode', 'California']
]

# Create DataFrames
person = pd.DataFrame(
    person_data,
    columns=['personId', 'firstName', 'lastName']
).astype({
    'personId': 'Int64',
    'firstName': 'object',
    'lastName': 'object'
})

address = pd.DataFrame(
    address_data,
    columns=['addressId', 'personId', 'city', 'state']
).astype({
    'addressId': 'Int64',
    'personId': 'Int64',
    'city': 'object',
    'state': 'object'
})


# Function definition
def combine_two_tables(person: pd.DataFrame, address: pd.DataFrame) -> pd.DataFrame:
    # Left join (same as SQL LEFT JOIN)
    merged = pd.merge(person, address, how='left', on='personId')

    # Select required columns
    result = merged[['firstName', 'lastName', 'city', 'state']].copy()

    # Sort (optional, for consistency)
    return result.sort_values(by=['firstName']).reset_index(drop=True)


# --- MAIN BLOCK ---
if __name__ == "__main__":
    result = combine_two_tables(person, address)
    print(result)