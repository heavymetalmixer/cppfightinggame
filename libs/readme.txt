Third party libraries go here.
Probably.

To get Raylib 5.5 specificaly follow the following steps:

1) Add the submodule: 

git submodule add https://github.com/raysan5/raylib.git


2) Move the submodule to inside the lib/raylib_5.5 folder:

git mv raylib libs/raylib/raylib_5.5


3) Set the SHA-1/commit of Raylib to c1ab645ca298a2801097931d1079b10ff7eb9df8
so the submodule is really Raylibi 5.5 stable:

cd libs/raylib/raylib_5.5/raylib

git checkout c1ab645ca298a2801097931d1079b10ff7eb9df8


4) Go back to the project's root:

cd ..
cd ..
cd ..
cd ..


5) 