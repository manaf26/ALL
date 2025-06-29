-- Keep a log of any SQL queries you execute as you solve the mystery.
--find the crime scene reports from that day
-- Keep a log of any SQL queries you execute as you solve the mystery.--find the crime scene reports from that day
SELECT description
    FROM crime_scene_reports
    WHERE year = '2024'
        AND day = '28'
        AND street = 'Humphrey Street'
        AND month = 'July'
        ;

--took place at 10:15am
--each of their (3) interview transcripts mentions the bakery.

-- find interviews that has mentioned the bakery name in it
SELECT transcript
    FROM interviews
    WHERE day = '28'
        AND month = '7'
        ;


-- within ten minutes of the theft drive away.
--> find the cars who left between 10:15 and 10:25
SELECT license_plate, minute
    FROM bakery_security_logs
    WHERE day = '28'
        AND month = '7'
        AND hour = '10'
        AND minute > '15' and minute < '25';

----------+---------------+--------+
--| exit     | 5P2BI95       | 16     |
--| exit     | 94KL13X       | 18     |
--| exit     | 6P58WS2       | 18     |
--| exit     | 4328GD8       | 19     |
--| exit     | G412CB7       | 20     |
--| exit     | L93JTIZ       | 21     |
--| exit     | 322W7JE       | 23     |
--| exit     | 0NTHK55       | 23


--Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money
--> find who withdraw money from that ATM in that Street
SELECT account_number
    FROM atm_transactions
    WHERE day = '28'
    AND month = '7'
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw';

----------------+
--account_number |
----------------+
--- 28500762       |
--| 28296815       |
--| 76054385       |
--| 49610011       |
--| 16153065       |
--| 25506511       |
--| 81061156       |
--| 26013199       |
----------------+


-- earliest flight out of Fiftyville tomorrow --The thief then asked the person on the other end of the phone to purchase the flight ticket

--> find who bought flight after the time of the theft (when the flight was purchased)

--> find the first id of flight the next day
SELECT flights.id --airports.full_name, airports.city , flights.id ,flights.day, flights.hour
    FROM flights
        JOIN airports ON flights.origin_airport_id = airports.id
    WHERE airports.city = 'Fiftyville'
        AND month = '7'
        AND day = '29'
    ORDER BY hour
    LIMIT 1;

--> find id the airport of fiftyville
SELECT id
    FROM airports
    WHERE city = 'Fiftyville'


-- those are people who fly at the first flight next day
SELECT passport_number FROM passengers WHERE flight_id = 36;
--+-----------------+
--| passport_number |
--+-----------------+
--| 7214083635      |
--| 1695452385      |
--| 5773159633      |
--| 1540955065      |
--| 8294398571      |
--| 1988161715      |
--| 9878712108      |
--| 8496433585      |
--+-----------------+


--> find someone whos plate is this and account is this and his passport number is this
SELECT name,id
    FROM people
        WHERE passport_number IN (SELECT passport_number
                                    FROM passengers
                                        WHERE flight_id = 36)

            AND license_plate IN (SELECT license_plate
                                    FROM bakery_security_logs
                                        WHERE day = '28'
                                            AND month = '7'
                                            AND hour = '10'
                                            AND minute > '15' and minute < '25')
    ;


-- the id of the of the suspect that has the account number
SELECT name,id
    FROM people
        WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36) --
            -- this is who left the bakery
            AND license_plate IN (SELECT license_plate
                                    FROM bakery_security_logs
                                        WHERE day = '28'
                                            AND month = '7'
                                            AND hour = '10'
                                            AND minute > '15' and minute < '25')
            --this is who withdraw money
            AND id IN (SELECT person_id
                         FROM bank_accounts
                            WHERE account_number IN ( SELECT account_number
                                                            FROM atm_transactions
                                                                WHERE day = '28'
                                                                    AND month = '7'
                                                                    AND atm_location = 'Leggett Street'
                                                                    AND transaction_type = 'withdraw'))
            -- this will cross refernce with who called
            AND name IN (SELECT name
                            FROM people
                            WHERE phone_number IN (SELECT caller
                                                        FROM phone_calls
                                                            WHERE day = '28'
                                                            AND month = '7'))
    ;
--+-------+--------+
--| name  |   id   |


--| Bruce | 686048 |

--Bruce called who by that date and time?
SELECT name
    FROM people

        WHERE phone_number IN (SELECT receiver
                                    FROM phone_calls
                                    WHERE caller = '(367) 555-5533'
                                    AND month = '7'
                                    AND day = '28'
                                    AND year = '2024'
                                    AND duration < 60)


        ;
--+---------+
--|  name   |
--+---------+
--| Gregory |
--| Carl    |
--| Robin   |
--| Deborah |
--+---------+

-- the destination of Bruce
SELECT airports.city --airports.full_name, airports.city , flights.id ,flights.day, flights.hour
    FROM airports
        JOIN flights ON destination_airport_id = airports.id
        WHERE month = '7'
        AND day = '29'
    ORDER BY hour
    LIMIT 1;
