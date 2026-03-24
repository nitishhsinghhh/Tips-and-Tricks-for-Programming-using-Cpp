-- OracleSetup.sql

-- Drop table if it exists
BEGIN
   EXECUTE IMMEDIATE 'DROP TABLE UserActivity';
EXCEPTION
   WHEN OTHERS THEN
      IF SQLCODE != -942 THEN
         RAISE;
      END IF;
END;
/

-- Create table
CREATE TABLE UserActivity (
    user_id NUMBER,
    activity_type VARCHAR2(20),
    activity_duration NUMBER
);

-- Insert sample data
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (1, 'free_trial', 45);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (1, 'free_trial', 30);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (1, 'paid', 60);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (1, 'paid', 90);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (1, 'paid', 75);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (2, 'free_trial', 55);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (2, 'free_trial', 25);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (2, 'free_trial', 50);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (2, 'cancelled', 0);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (3, 'free_trial', 70);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (3, 'free_trial', 60);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (3, 'free_trial', 80);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (3, 'paid', 50);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (3, 'paid', 55);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (3, 'paid', 85);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (4, 'free_trial', 40);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (4, 'free_trial', 35);
INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES (4, 'paid', 45);

COMMIT;

-- Run your Oracle query
SELECT
    user_id,
    ROUND(SUM(CASE WHEN activity_type = 'free_trial' THEN activity_duration ELSE 0 END) * 1.0 /
          NULLIF(COUNT(CASE WHEN activity_type = 'free_trial' THEN 1 END),0), 2) AS trial_avg_duration,
    ROUND(SUM(CASE WHEN activity_type = 'paid' THEN activity_duration ELSE 0 END) * 1.0 /
          NULLIF(COUNT(CASE WHEN activity_type = 'paid' THEN 1 END),0), 2) AS paid_avg_duration
FROM UserActivity
GROUP BY user_id
HAVING 
    COUNT(CASE WHEN activity_type = 'free_trial' THEN 1 END) > 0 AND
    COUNT(CASE WHEN activity_type = 'paid' THEN 1 END) > 0
ORDER BY user_id;