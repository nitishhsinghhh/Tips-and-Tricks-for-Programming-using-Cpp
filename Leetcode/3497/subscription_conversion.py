# Run commands:
# source /Users/nitishsingh/Documents/GitHub/Tips-and-Tricks-for-Programming-using-Cpp/Repo/venv/bin/activate
# python3 subscription_conversion.py

import pandas as pd
# Sample data
data = [
    [1, '2023-01-01', 'free_trial', 45],
    [1, '2023-01-02', 'free_trial', 30],
    [1, '2023-01-05', 'free_trial', 60],
    [1, '2023-01-10', 'paid', 75],
    [1, '2023-01-12', 'paid', 90],
    [1, '2023-01-15', 'paid', 65],
    [2, '2023-02-01', 'free_trial', 55],
    [2, '2023-02-03', 'free_trial', 25],
    [2, '2023-02-07', 'free_trial', 50],
    [2, '2023-02-10', 'cancelled', 0],
    [3, '2023-03-05', 'free_trial', 70],
    [3, '2023-03-06', 'free_trial', 60],
    [3, '2023-03-08', 'free_trial', 80],
    [3, '2023-03-12', 'paid', 50],
    [3, '2023-03-15', 'paid', 55],
    [3, '2023-03-20', 'paid', 85],
    [4, '2023-04-01', 'free_trial', 40],
    [4, '2023-04-03', 'free_trial', 35],
    [4, '2023-04-05', 'paid', 45],
    [4, '2023-04-07', 'cancelled', 0]
]

# Create DataFrame
user_activity = pd.DataFrame(data, columns=['user_id', 'activity_date', 'activity_type', 'activity_duration'])
user_activity['activity_date'] = pd.to_datetime(user_activity['activity_date'])

# Function definition
def analyze_subscription_conversion(user_activity: pd.DataFrame) -> pd.DataFrame:
    round2 = lambda x: round(x + 1e-4, 2)

    def findMean(activity: str, avg: str) -> pd.DataFrame:
        df = (
            user_activity[user_activity['activity_type'] == activity]
            .groupby('user_id', as_index=False)['activity_duration']
            .mean()
        )
        df[avg] = df['activity_duration'].apply(round2)
        return df[['user_id', avg]]

    result = pd.merge(findMean('free_trial', 'trial_avg_duration'),
                      findMean('paid', 'paid_avg_duration'),
                      on='user_id')
    return result.sort_values('user_id').reset_index(drop=True)

# --- MAIN BLOCK ---
if __name__ == "__main__":
    result = analyze_subscription_conversion(user_activity)
    print(result)