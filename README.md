## TODO
- Remove Matrix2D / Vector2D if able
 - If not, consider consolidating
- Change the game to use fixed sim + variable frame rate

- remove all the 0.0f literals (right hand values)
- Change all variables to east const

- Make all warnings into errors
- Add tests as a separate, optional build step
- Add CI for the GitHub project
- try out ctest
- add travis.ci for CI
- change warnings into errors (display all warnings)
- read through this - https://github.com/lefticus/crategameengine/blob/master/game_loader/main.cpp
- Figure out how to use Valgrind cachegrind for debugging
 - https://austinmorlan.com/posts/entity_component_system/#the-system
- Change the CMake projects so any change to engine will compile when
  I run CMake on the game

https://dopresskit.com/
Youtube thumbnail ideas - https://imgur.com/a/mTV0mi9

https://youtu.be/fdAOPHgW7qM?t=2484
- Swept sphere vs rectangular solid test


## Game Loop
- https://www.reddit.com/r/cpp_questions/comments/5zni9x/fixed_physics_timestep_game_loop_running_too_fast/
- https://gafferongames.com/post/fix_your_timestep/
- https://stackoverflow.com/questions/43302268/why-use-integration-for-a-fixed-timestep-game-loop-gaffer-on-games
https://github.com/PacktPublishing/Game-Programming-Using-Qt-5-Beginners-Guide-Second-Edition
- https://www.titanwolf.org/Network/q/d1c6c308-6d7d-4c10-be61-1660cbf3cb12/y
- https://stackoverflow.com/questions/22121664/how-to-implement-a-game-loop-with-c-and-qtquick

- Unhelpful - https://stackoverflow.com/questions/18065004/how-to-adjust-a-game-loop-frame-rate
- FPS counter - https://stackoverflow.com/questions/28530798/how-to-make-a-basic-fps-counter




# 2D Vector Attempt
http://www.danielsoltyka.com/programming/2010/05/30/c-vector2d-rectangle-classes/
https://codereview.stackexchange.com/questions/26608/review-of-2d-vector-class


## Information On Operator Overloading
https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading/4421729#4421729
https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
https://stackoverflow.com/questions/856542/elegant-solution-to-duplicate-const-and-non-const-getters
https://www.geeksforgeeks.org/function-overloading-and-const-functions/
https://stackoverflow.com/questions/13410848/c-should-i-make-operator-const-and-does-it-return-a-reference

## Templates and non-member functions
https://stackoverflow.com/questions/2881925/c-non-member-functions-for-nested-template-classes
https://stackoverflow.com/questions/38729266/nonmember-template-function/38729383
https://stackoverflow.com/questions/38729266/nonmember-template-function/38729383


## More Stuff


https://stackoverflow.com/questions/498106/how-do-i-compile-a-visual-studio-project-from-the-command-line
https://github.com/davidzaadstra/vc2clangdb
https://clangpowertools.com/blog/generate-json-compilation-database.html
https://docs.microsoft.com/en-us/cpp/build/building-on-the-command-line?view=msvc-160


## Interesting CMake things
https://riptutorial.com/cmake/example/7501/simple--hello-world--project
> cmake -E chdir build cmake ..
https://gitlab.kitware.com/cmake/community/-/wikis/doc/ctest/Testing-With-CTest
> cmake --help-command enable_testing
