### valgrind --leak-check=full --show-leak-kinds=all ./a.out
==2006== Memcheck, a memory error detector  
==2006== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.  
==2006== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info  
==2006== Command: ./a.out  
==2006==  
==2006== error calling PR_SET_PTRACER, vgdb might block  
Some type information -  
Size of int is 4 bytes.  
Size of float is 4 bytes.  
Size of std::string is 32 bytes.  
Size of ArbitraryData is 40 bytes.  

Checking the amount of free memory before any allocs  
              total        used        free      shared  buff/cache   available  
Mem:          17039        6691       10113          18         234       10211  
Swap:         51539         283       51255  
 --------- Starting the mass allocs in 100 MB chunks ----------  
Batch number: 0  
Batch number: 1  
Batch number: 2  
Batch number: 3  
Batch number: 4  
Batch number: 5  
Batch number: 6  
Batch number: 7  
Batch number: 8  
Batch number: 9  
Checking the amount of free memory after all allocs  
              total        used        free      shared  buff/cache   available  
Mem:          17039       11862        4942          18         234        5039  
Swap:         51539         283       51255  
Ending program....  
==2006==  
==2006== HEAP SUMMARY:  
==2006==     in use at exit: 1,200,000,000 bytes in 25,000,001 blocks  
==2006==   total heap usage: 25,000,003 allocs, 2 frees, 1,200,073,216 bytes allocated  
==2006==  
==2006== 200,000,000 bytes in 1 blocks are possibly lost in loss record 1 of 2  
==2006==    at 0x483577F: malloc (vg_replace_malloc.c:299)  
==2006==    by 0x109386: main (in /mnt/d/workspace/cpp-diary/small_programs/memory_monitor/a.out)  
==2006==  
==2006== 1,000,000,000 bytes in 25,000,000 blocks are possibly lost in loss record 2 of 2  
==2006==    at 0x4835DEF: operator new(unsigned long) (vg_replace_malloc.c:334)  
==2006==    by 0x10947B: main (in /mnt/d/workspace/cpp-diary/small_programs/memory_monitor/a.out)  
==2006==  
==2006== LEAK SUMMARY:  
==2006==    definitely lost: 0 bytes in 0 blocks  
==2006==    indirectly lost: 0 bytes in 0 blocks  
==2006==      possibly lost: 1,200,000,000 bytes in 25,000,001 blocks  
==2006==    still reachable: 0 bytes in 0 blocks  
==2006==         suppressed: 0 bytes in 0 blocks  
==2006==  
==2006== For counts of detected and suppressed errors, rerun with: -v  
==2006== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0) 