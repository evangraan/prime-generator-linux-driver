# Introduction

This code base contains a small Linux C character driver that outputs prime numbers, character by character, with prime numbers separated by tabs.

# Development

Instructions are for Linux operating systems, debian-based (I used Ubuntu 18.04)

```
sudo apt-get install aptitude
sudo aptitude update
sudo aptitude install build-essential

git clone https://github.com/evangraan/prime-generator-linux-driver.git
cd prime-generator-linux-driver
make
sudo make load
sudo make unload
```

# Testing

Once the kernel module has been loaded, test it as follows:

```
$ cat /proc/modules | grep prime
prime_generator 20480 0 - Live 0x0000000000000000 (POE)

$ cat /proc/devices | grep prime
243 prime-generator

$ sudo mknod /dev/prime-generator c 243 0

$ cat /dev/prime-generator
2	3	5	7	11	13	17	19	23	29	31	37	41	43	47	53	59	61	67	71	73	7983	89	97	101	103	107	109	113	127	131	137	139	149	151	157	163	167	173	179	181	191	19197	199	211	223	227	229	233	239	241	251	257	263	269	271	277	281	283	293	307	311	313	31331	337	347	349	353	359	367	373	379	383	389	397	401	409	419	421	431	433	439	443	449	45461	463	467	479	487	491	499	503	509	521	523	541	547	557	563	569	571	577	587	593	599	60607	613	617	619	631	641	643	647	653	659	661	673	677	683	691	701	709	719	727	733	739	74751	757	761	769	773	787	797	809	811	821	823	827	829	839	853	857	859	863	877	881	883	88907	911	919	929	937	941	947	953	967	971	977	983	991	997	1009	1013	1019	1021	1031	1033	1039	1049	1051	1061	1063	1069	1087	1091	1093	1097	1103	1109	1117 ...
```

# Kernel logging

```
[  310.709353] [Prime generator] initializing
[  310.709355] [prime-generator] register_generator()
[  310.709362] [prime-generator] character device rgistered (243.0...255)
[  439.053055] [prime-generator] read 131072 characters from offset = 0
[  439.073750] [prime-generator] read 131072 characters from offset = 4805
[  482.069176] [Prime generator] exiting
[  482.069178] [prime-generator] unregister_generator()
[  487.433754] [Prime generator] initializing
[  487.433755] [prime-generator] register_generator()
[  487.433759] [prime-generator] character device rgistered (243.0...255)
[  498.017105] [prime-generator] read 131072 characters from offset = 0
```
