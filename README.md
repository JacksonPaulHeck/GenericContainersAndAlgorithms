# Program 2
## By: JP Heck and Garrett Webb

For data generation, we began with the randomized set which we then ordered for the ascending and descending sets, finishing by randomizing it again and substituting 20% and 40% of the values with already present values. To check if our algorithms were working properly, we ran the supposedly sorted sets through checker algorithms.

An interesting and noticeable effect the character data seemed to have on the relative speed of the algorithms was drastically increasing the time taken to sort ascending sets without proportionally similar change to time taken to sort other sets (e.g. see "Quick Sort Performance on Integer Sets" and "Quick Sort Performance on String Sets" in data.xlsx).

Overall, when compared to one another, the different sorting algorithms' relative performances seem to replicate the findings of the Data Structures sorting algorithm project. However, every algorithm's time taken inexplicably seems to spike on the first set in the ascending order group. This is believed to be computer error, or likely another action is being timed in addition to the sorting itself (e.g. see "Heap Sort Performance on Integer Sets"). However, we were unable to identify the true source of this issue.