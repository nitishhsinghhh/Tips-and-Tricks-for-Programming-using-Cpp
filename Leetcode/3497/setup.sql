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
(1, 'paid', 75),
(2, 'free_trial', 55),
(2, 'free_trial', 25),
(2, 'free_trial', 50),
(2, 'cancelled', 0),
(3, 'free_trial', 70),
(3, 'free_trial', 60),
(3, 'free_trial', 80),
(3, 'paid', 50),
(3, 'paid', 55),
(3, 'paid', 85),
(4, 'free_trial', 40),
(4, 'free_trial', 35),
(4, 'paid', 45),
(4, 'cancelled', 0);
GO