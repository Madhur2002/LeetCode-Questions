<h2><a href="https://leetcode.com/problems/number-of-good-paths/">2421. Number of Good Paths</a></h2><h3>Hard</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">There is a tree (i.e. a connected, undirected graph with no cycles) consisting of <code style="user-select: auto;">n</code> nodes numbered from <code style="user-select: auto;">0</code> to <code style="user-select: auto;">n - 1</code> and exactly <code style="user-select: auto;">n - 1</code> edges.</p>

<p style="user-select: auto;">You are given a <strong style="user-select: auto;">0-indexed</strong> integer array <code style="user-select: auto;">vals</code> of length <code style="user-select: auto;">n</code> where <code style="user-select: auto;">vals[i]</code> denotes the value of the <code style="user-select: auto;">i<sup style="user-select: auto;">th</sup></code> node. You are also given a 2D integer array <code style="user-select: auto;">edges</code> where <code style="user-select: auto;">edges[i] = [a<sub style="user-select: auto;">i</sub>, b<sub style="user-select: auto;">i</sub>]</code> denotes that there exists an <strong style="user-select: auto;">undirected</strong> edge connecting nodes <code style="user-select: auto;">a<sub style="user-select: auto;">i</sub></code> and <code style="user-select: auto;">b<sub style="user-select: auto;">i</sub></code>.</p>

<p style="user-select: auto;">A <strong style="user-select: auto;">good path</strong> is a simple path that satisfies the following conditions:</p>

<ol style="user-select: auto;">
	<li style="user-select: auto;">The starting node and the ending node have the <strong style="user-select: auto;">same</strong> value.</li>
	<li style="user-select: auto;">All nodes between the starting node and the ending node have values <strong style="user-select: auto;">less than or equal to</strong> the starting node (i.e. the starting node's value should be the maximum value along the path).</li>
</ol>

<p style="user-select: auto;">Return <em style="user-select: auto;">the number of distinct good paths</em>.</p>

<p style="user-select: auto;">Note that a path and its reverse are counted as the <strong style="user-select: auto;">same</strong> path. For example, <code style="user-select: auto;">0 -&gt; 1</code> is considered to be the same as <code style="user-select: auto;">1 -&gt; 0</code>. A single node is also considered as a valid path.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong class="example" style="user-select: auto;">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/08/04/f9caaac15b383af9115c5586779dec5.png" style="width: 400px; height: 333px; user-select: auto;">
<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
<strong style="user-select: auto;">Output:</strong> 6
<strong style="user-select: auto;">Explanation:</strong> There are 5 good paths consisting of a single node.
There is 1 additional good path: 1 -&gt; 0 -&gt; 2 -&gt; 4.
(The reverse path 4 -&gt; 2 -&gt; 0 -&gt; 1 is treated as the same as 1 -&gt; 0 -&gt; 2 -&gt; 4.)
Note that 0 -&gt; 2 -&gt; 3 is not a good path because vals[2] &gt; vals[0].
</pre>

<p style="user-select: auto;"><strong class="example" style="user-select: auto;">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/08/04/149d3065ec165a71a1b9aec890776ff.png" style="width: 273px; height: 350px; user-select: auto;">
<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
<strong style="user-select: auto;">Output:</strong> 7
<strong style="user-select: auto;">Explanation:</strong> There are 5 good paths consisting of a single node.
There are 2 additional good paths: 0 -&gt; 1 and 2 -&gt; 3.
</pre>

<p style="user-select: auto;"><strong class="example" style="user-select: auto;">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/08/04/31705e22af3d9c0a557459bc7d1b62d.png" style="width: 100px; height: 88px; user-select: auto;">
<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> vals = [1], edges = []
<strong style="user-select: auto;">Output:</strong> 1
<strong style="user-select: auto;">Explanation:</strong> The tree consists of only one node, so there is one good path.
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">n == vals.length</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= n &lt;= 3 * 10<sup style="user-select: auto;">4</sup></code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">0 &lt;= vals[i] &lt;= 10<sup style="user-select: auto;">5</sup></code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">edges.length == n - 1</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">edges[i].length == 2</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">0 &lt;= a<sub style="user-select: auto;">i</sub>, b<sub style="user-select: auto;">i</sub> &lt; n</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">a<sub style="user-select: auto;">i</sub> != b<sub style="user-select: auto;">i</sub></code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">edges</code> represents a valid tree.</li>
</ul>
</div>