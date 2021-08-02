# quiz_code

A Complete quiz system where player signup, sigin and play the quiz and privilage for the Admin to control the entire quiz result is developed using OOPS and file handling concepts in C++.
- Signup details are stored in `details.txt` file.
- Questions, options and its answer_options are stored sequentially in a file `QP.txt`.
- Results are stored with person details in `result.txt`.
- Also this quiz has two levels.
   - Level1 -> It has random 5 questions and player will get 10 marks for right answer and -5 for wrong answers.
   - Level2 -> It has random 10 questions, which further divide into round1 and round2.
      - Each round has 5 questions. Player will get 10 marks for correct answer and -2 forwrong answer.
      - Player has to score atleast 30 marks in first round to get qualify for the second round.
      - At the end average of two round will be given as result of the player.
- At the end rank will be displayed.
- Admin can login with `username: admin` and `password: 12345` to edit the quiz results.
