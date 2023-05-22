**$$Question .$$ If $$P(x)$$ denotes a polynomial of degree $$n$$ such that $$P(k)=\frac{k}{k+1}$$ for $$k=0,1,2,\ldots,n$$, determine $$P(n+1)$$.** 

**Sol :** 

**Let $$Q(x) = (x+1)P(x) - x$$, and clearly, $$Q(x)$$ has a degree of $$n+1$$.**

**Then, for $$k=0,1,2,\ldots,n$$, $$Q(k) = (k+1)P(k) - k = (k+1)\cdot \dfrac{k}{k+1} - k = 0$$.**

**Thus, $$k=0,1,2,\ldots,n$$ are the roots of $$Q(x)$$.**

**Since these are all $n+1$ of the roots of the $$n+1^{\text{th}}$$ degree polynomial, we can write $$Q(x)$$ as $$Q(x) = c(x)(x-1)(x-2) \cdots (x-n)$$ where $$c$$ is a constant.**

**Thus, $$(x+1)P(x) - x = c(x)(x-1)(x-2) \cdots (x-n).$$**

**We plug in $$x = -1$$ to cancel the $$(x+1)P(x)$$ and find $$c$$:**

 **$$-(-1) = c(-1)(-1-1)(-1-2) \cdots (-1-n)$$**
 $$\hspace{0.25cm}1 = c(-1)^{n+1}(1)(2) \cdots (n+1)$$ 
 $$\hspace{0.25cm}c = (-1)^{n+1}\dfrac{1}{(n+1)!}$$

**Finally, plugging in $$x = n+1$$ to find $$P(n+1)$$ gives:**

$$Q(n+1)=(n+2)P(n+1)-(n+1)$$
$$\hspace{0.5cm}(-1)^{n+1}\dfrac{1}{(n+1)!}\cdot(n+1)! =(n+2)P(n+1)-(n+1)$$ $$\hspace{0.5cm}(-1)^{n+1}=(n+2)P(n+1)-(n+1)$$
$$\hspace{0.5cm}(-1)^{n+1}+(n+1)=(n+2)P(n+1)$$
$$\hspace{0.5cm}P(n+1) = \dfrac{(-1)^{n+1} + (n+1)}{n+2}$$

**If $$n$$ is even, this simplifies to $$P(n+1) = \dfrac{n}{n+2}$$. If $$n$$ is odd, this simplifies to $$P(n+1) = 1$$. $$\Box$$** 