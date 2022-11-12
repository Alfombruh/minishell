<h1 align="center"> BA$H-ADOS </h1>
<p align="center">
  <img src="image/minishell.png" alt="minishell 42 project badge"/>
</p>

## __Minishell-My Tale__

This is a project that really testes you, but it isn't really that hard. If you organize your mind before starting to write code it 100% will make it way easier to pass the project faster, since you'll have a clean program and wont have to patch many things.

If you are not too familiar with the terminal I'd recommend starting by testing things on the termina. What are pipes? How do they work? What are redirections? enviroment variables? expansions? ... Before starting to work on those I'd make sure to know what they really are and how they work so their implementation to your code is the cleanest and easiest one.

Supossing that you want to start to make the mandatory part of minishell my order of priorities would be this:
1. Parsing/Lexing
2. Expanding
3. Forking
5. Doing Builtins
6. Doing the redirections

If you start this way I'd believe you would end up with a clean code and a code that's hard to break. This is a project that can give so many segfaults you wouldn't believe it, but almost all those come from the parsing, so if you make a really good parser the rest of the minishell would have little to no segfaults, leaks, etc

The real key to finishing this project is organization

__Good luck with your minishell, and welcome to hell__

## __Minishell test strings__

Te worst part about minishell isn't allways coding it, but fixing errors, segfaults, leaks, and so on. Minishell does not have to output the same bash does, this test are to find out if your parser, lexer, expander ... are actually working fine and to try to help you find things about your code.

__enviroment things__
```bash
$> export HOME=$USER USER=$HOME
$> export a="="
$> export a==========b
$> export a=a b=b c=c
$> unset a
$> unset "something that doesnt exist"
$> unset "arg" "arg2" "arg3" ...
```

__messing with the path__
```bash
$> unset HOME
$> unset PATH
$> cd
$> cd "directory"
$> pwd
$> ls
#now that we've change the path we need to go to /bin/. and copy the ls, or other command\s you want, got to Deskptop and set it as the PATH, then check if you can execute the binries
$> export PATH="/Users/'user'/Desktop/"
$> ls 
```

__expansions__
```bash
$> $$
$> $?
$> $HOME$USER
$> $"USER""$HOME"
$> '$USER' 
$> $'USER'
$> "$USER$HOME"
``` 

__forking__
```bash
$> ls -la | wc -l | bc

$> ls -la | wc -l | cat | cat | cat | bc

$> ls -la | wc -l
```

__parsing + redis__
```bash
$> echo hello > "|"
$> cat "|"

$> >"\'\out\'\" echo hola

$> echo hi > "hol"hola my nameis" PacoSanz "whats yours? test uuu"a"

$> ls >out>out2>out4>ut"<<"<<out
```
__Outstanding Project(forking)__
```bash
$> top | cat
```
I dont take in mind if this doesnt work. If you were to create a child procces, execute the command and then exit and create the a new child to execute the next command, this combination would make you minishell to stop workin. Obviously this shoulnt break your signals nor break your minishell. 

To fix this the only solution I've seen is to have 2 while loops for the forking. In the first one you create all the child proccess and make them wait with signals, and when they are all created you send another signal so they all start working at the same time.

__Redirections one shot test__
```bash
$> cat >out > out2 >>out3 >> out >>"jose"juan"<123" >>EOF >>EOF1 >>EOF2 >> EOF3
$> cat <"josejuan<123"
```

This is a full redirections check, if you were to treat them like bash does, you shoudl be creating; out; out2; out3; josejuan<123; and opening 4 heredocs. To close the heredocs you should have to close them in orther and only redirect the last one. Then use cat to "josejuan<123" to se if the redirections worked properly

## __PD__

If you want to add more test, DM on slack ("jofernan"), or pull request me

## __Shoutouts__

- [Fasu, my minishell partner. Now that the project is finished we are no longer friends][fasu]
- [Eperaita, official debugger, tester, REPIPING creator and neurotica profesiona][eperaita]
- [ceciarmy, por ser una persona increible][ceciarmy]
- and everybody else that I forgot to mention

## License

XD

# <3

[//]: #
 [fasu]: <https://github.com/f4su>
 [eperaita]: <https://github.com/eperaita>
 [ceciarmy]: <https://www.instagram.com/ceciarmy/?hl=es>
