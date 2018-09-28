# (Optional) Reaction Game
On to the sort of optional part of the lab. I only say "sort of" because I really think that you should try to implement a game just to not only have a little fun with the class, but also start thinking about what behaviors you want your system to exhibit. Below are only a few recommendations I can think of, but if you want, please show me your creative side and think of another game to implement.

## Task
The final part of this lab is to generate a game using buttons, timers, and LEDS that is meant to be played with let's say 2+ players. Your game does not have to be complicated, however, I think it would be kind of cool as people start making these games that we can test them out in lab. Along with some awesome documentation to explain how to play your game, you need to also demonstrate to your Professor and/or the Lab Instructor that your game actually works to get credit for this part of the lab. The reason we want to see it in person is A) so we can bask in the glory that is your game, and B) so we can get a good look at the game and see what you have implemented from the lab exercises so far. This is not meant to be a "Grill session" where we rake you over the coals about every single line of code, but we are probably going to ask a few questions just to get an idea for the different ways people are implementing these game ideas.

## "But what processor should I be doing this on?"
Since this is technically an optional part of the lab, we are not going to force you into picking just one processor or make you do it for them all. What I personally would love to see is people using boards like the FR6989 or F5529 and take advantage of a ton of I/O to maybe do something interesting with LED displays or multiple inputs.

### Game Ideas
#### Reaction
This would be a 2 player game where your two players after resetting the processor press their buttons to initialize the game. After at least 5 seconds, one of the LEDs should turn on and your processor then has to determine who was the first person to press the button. The winner could be indicated by blinking particular LEDs. Once you get the core functionality working, you should also add false start protection so players who press the button too early are automatically disqualified.

#### Rapid Pressing
The object of this 2 player game would be to see who can press their button the fastest up to an arbitrary number of times, for example 50 times. Upon your processor starting up, each player should hold their button down to indicate the start of the game. From that point the LEDs could blink 3 times and after that, both players begin pressing the buttons as fast as possible. First player to the number of button presses wins and can be indicated by flashing LEDs. Remember! Since you are counting the number of times a button is pressed, you need to make sure that you are debouncing properly to ensure there is no inadvertent cheating.
