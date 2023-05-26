
The circle $O'(r')$ touches $O(r)$ internally, and a chain of contact circles $O_i(r_i), i = 1, 2, 3, 4$, is inscribed in the lune formed by $O(r)$ and $O'(r')$. Show that
$1 / r1 + 3 / r3 = 3 / r2 + 1 / r4.$

$Sol.$

The sangaku is easily solved by a general formula for the radius of the circles in the lune:
$r_t = r r'(r - r') / (r r' + t^2(r - r')^2)$,

where circles in the chain tangent to each other correspond to values of $t$ different by $1!$ Using $A = r r'$ and $B = r - r'$, we can then write
$r_1 = A / (A + B²)$,
$r_2 = A / (A + 2²B²)$,
$r_3 = A / (A + 3²B²)$,
$r_4 = A / (A + 4²B²)$.

Substituting this into
 	$1 / r_1 + 3 / r_3 = 3 / r_2 + 1 / r_4.$

we get to verify that
 	1 + 3·3² = 3·2² + 4²,

which is of course true.

The $r_t$ formula comes from Ellipse of Arbelos Problem

As shown below the cirlces with radius $a_1$ and $a_2$ we have a locus of points for the circles
tanget to both the circles $A$ and $B$. Let us call it the Circle $C$.

The locus is like as shown in Fig.

![Ellipse in Arbelos](https://github.com/mostlovedpotato/Dir/blob/master/2023/May/26/image.png)

First result we get about this locus is 

The locus of the center of $C$ as it sweeps out $M$ is an ellipse with semiaxes the arithmetic mean $(a_1 + a_2)/2$ and the geometric mean $√(a_1 \cdot a_2)$ of the radii $a_1$ and $a_2$.

A glance at a figure shows that the center of $C$ is always in such a position that the sum of its distances from $(a_1, 0)$ and $(a_2, 0)$ is $a_1 + a_2$.
That the major semiaxis of the ellipse is $(a_1 + a_2)/2$ is indeed rather obvious. To determine the minor semiaxis, consider circle $C$ with the center at the topmost point of the ellipse. The triangle of the centers of the three circles will then be isosceles, with the legs equal to $(a_1 + a_2)/2$ and the base $a_2 - a_1$.
The altitude $h$ of the triangle is found from the Pythagorean theorem:

$$h² = [(a_1 + a_2)/2]^2 - [(a_2 - a_1)/2]^2$$

so that indeed, $h^2 = a_1 \cdot a_2$.

If $C_t$ is a circle of radius $r_t$ and center $P_t(x_t, y_t)$ where

$$t = a_1 \cdot a_2 + t^2 (a_2 - a_1)^2$$,
$$r_t = a_1 \cdot a_2(a_2 - a_1) / φ_t$$,
$$x_t = a_1 \cdot a_2 \cdot (a_2 + a_1) / φ_t$$,
$$y_t = 2 \cdot t \cdot r_t.$$
then, for any real value of $t, C_t$ lies in M and is tangent to $A_1, A_2,$ and $C_{t-1}$.