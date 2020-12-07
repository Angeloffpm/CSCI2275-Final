# Civil War Simulator 2020

## The Concept
2020 has been a wild year. Among all the turmoil that has plagued the country, the United States has gone to civil war! Each state claims their own army and wants to claim the United States for themselves! You, the Player, get to choose which State to play as, and develop a strategy to take over the United States!

## Instructions
To start running the game, open the project in any terminal, compile it if necessary using the command:
g++ -std=c++11 CivilWarSimulator.cpp UnitedStates.cpp Player.cpp AttackingQueue.cpp -o CivilWarSimulator
And, run the program by typing ./CivilWarSimulator in the terminal.
You will begin the game by choosing which state you want to play as. This is case sensitive, so in order to choose Colorado, you will need to type "Colorado" instead of "colorado" for the game to recognize the State. Case sensitivity applies to all cases where the game asks for a State. Each round you will be given the option of attacking, defending, or reinforcing. The game ends when you have either conquered every state, and therefor win! Or, when your army size falls below 100,000 troops, and you can no longer be an active force in the War, and therefor you lose.
### Attacking
Choosing to attack will allow you to attack a neighboring state. The bigger the army of the neighboring state however, the lower your chances of conquering them are. For beginners, a good strategy may be to target smaller states first, and build your army bigger by conquering them, before taking on the bigger states. If you lose an attack, you will lose a mostly random portion of your army. Attacking can be risky, but you will need to attack in order to win.
### Defending
Choosing to defend will bolster your defenses in preparation for an oncoming attack. If you see a large threat is planning an attack on you, this may be the option you want to choose for the round, as it will greatly increase your chances of successfully defending from the attacking state.
### Reinforce
Choosing to reinforce your army can boost both attacking and defending chances, as it is a flat increase in army size. Having a bigger army will increase your chances of a successful attack and defense. Do this when it is safe to, and before taking on bigger states.

## CSCI 2275 Content
Civil War Simulator 2020 utilizes two key data structures: Graphs and Queues. The entire United States is built as a Graph, each State representing a vertex and its bordering states create edges. This allows each State to be limited to who it can attack, based on its adjacent states. You will also face a queue for attackers. Each round, there is a chance that a neighboring state will be queued to attack you. Each round, there is also a chance that the attacking queue will dequeue and you will be attacked by the State at the front of the queue. If you know a larger State like California is planning on attacking soon, you may want to defend your state or reinforce your army, as opposed to attacking a neighboring state.