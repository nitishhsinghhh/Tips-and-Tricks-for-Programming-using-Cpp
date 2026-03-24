IF OBJECT_ID('UserActivity', 'U') IS NOT NULL
    DROP TABLE UserActivity;
GO

CREATE TABLE UserActivity (
    user_id INT,
    activity_type VARCHAR(20),
    activity_duration INT
);
GO

INSERT INTO UserActivity (user_id, activity_type, activity_duration) VALUES
(1, 'free_trial', 45),
(1, 'free_trial', 30),
(1, 'paid', 60),
(1, 'paid', 90),
(2, 'free_trial', 20),
(2, 'paid', 40),
(3, 'free_trial', 15);
GO