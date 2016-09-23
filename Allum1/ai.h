/*
** ai.h for Allum1 in /home/pignol_j/Rendu/CPE_2015_Allum1
**
** Made by Pignolet Julien
** Login   <pignol_j@epitech.net>
**
** Started on  Wed Feb 17 15:11:47 2016 Pignolet Julien
** Last update Wed Feb 17 15:13:00 2016 Pignolet Julien
*/

#ifndef AI_H_
#define AI_H_

#define AI (((i <= allum.l1) && ((xor = i ^ allum.l2 \
				  ^ allum.l3 ^ allum.l4) \
				 == 0)) ? (tot = (allum.l1 + allum.l2 + allum.l3 + allum.l4) - \
					   (allum.l1 - i), (allum.l2 + allum.l3 + allum.l4 == 1 \
							    || (tot == 4 && \
								allum.l2 == 1 && allum.l3 == 1 && \
								allum.l4 == 1))	\
					   ? (match = allum.l1 - i + 1) : ((tot == 0 || \
									    tot == 2 || tot == 3) ? \
									   (match = allum.l1 - i - 1) : \
									   (match = allum.l1 - i)), allum.l1 \
					   -= match, line = 1) : (((i <= allum.l2) && \
								   ((xor = allum.l1 ^ i \
								     ^ allum.l3 ^ allum.l4) == 0)) ? \
								  (tot = (allum.l1 + allum.l2 \
									  + allum.l3 + allum.l4) - \
								   (allum.l2 - i), (allum.l1 + \
										    allum.l3 + allum.l4 == 1 || \
										    (tot == 4 && allum.l1 == 1 && \
										     allum.l3 == 1 && \
										     allum.l4 == 1)) ? \
								   (match = allum.l2 - i + 1) : \
								   ((tot == 0 || tot == 2 || \
								     tot == 3) ? (match = allum.l2 - i - 1) : \
								    (match = allum.l2 - i)), \
								   allum.l2 -= match, \
								   line = 2) : (((i <= allum.l3) && \
										 ((xor = allum.l1 ^ \
										   allum.l2 ^ i ^ allum.l4) == 0)) ? \
										(tot = (allum.l1 + allum.l2 + \
											allum.l3 + allum.l4) - \
										 (allum.l3 - i), (allum.l1 + \
												  allum.l2 + allum.l4 == 1 \
												  || (tot == 4 && \
												      allum.l1 == 1 && \
												      allum.l2 == 1 && \
												      allum.l4 == 1)) ? \
										 (match = allum.l3 - i + 1) : \
										 ((tot == 0 || tot == 2 || tot == 3) ? \
										  (match = allum.l3 - i - 1) : \
										  (match = allum.l3 - i)), \
										 allum.l3 -= match, line = 3) : \
										(((i <= allum.l4) && \
										  ((xor = allum.l1 ^ allum.l2 ^ \
										    allum.l3 ^ i) == 0)) ? \
										 (tot = (allum.l1 + allum.l2 + \
											 allum.l3 + allum.l4) - \
										  (allum.l4 - i), (allum.l1 + allum.l2 \
												   + allum.l3 == 1 || \
												   (tot == 4 && allum.l1 \
												    == 1 && allum.l2 == \
												    1 && allum.l3 == 1)) \
										  ? (match = allum.l4 - i + 1) : \
										  ((tot == 0 || tot == 2 || \
										    tot == 3) ?	\
										   (match = allum.l4 - i - 1) : \
										   (match = allum.l4 - i)), allum.l4 \
										  -= match, line = 4) : (0)))))

#endif /* !AI_H_ */
