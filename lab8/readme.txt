Alejandro Alvarado
CS35L
readme.txt

1. Some of the first issues I encountered
   was how I was going to split the work
   between threads. Luckily the TA gave
   us a clue to encapsulate all the for
   loops within the thread function.

2. A minor problem encountered was which
   variables were needed to become global
   and how to generally move the code around
   so that the thread was able to work
   properly.

3. Another problem that I encountered was
   the scaled_color array. It was needed
   to color the image and was a bit difficult
   to understand in the beginning as it was
   not mentioned in class. With some help I
   managed to color the pixels with RGB using
   the information contained in scaled_color[][][0],
   scaled_color[][][1], and scaled_color[][][2].

4. Creating the threads required a malloc
   to store at runtime.

   Therefore, the hardest part of the project
   was figuring out the problem about coloring
   the picture with the right RGB value
