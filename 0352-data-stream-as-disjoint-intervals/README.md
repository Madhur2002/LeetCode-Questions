<h2><a href="https://leetcode.com/problems/data-stream-as-disjoint-intervals/">352. Data Stream as Disjoint Intervals</a></h2><h3>Hard</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">Given a data stream input of non-negative integers <code style="user-select: auto;">a<sub style="user-select: auto;">1</sub>, a<sub style="user-select: auto;">2</sub>, ..., a<sub style="user-select: auto;">n</sub></code>, summarize the numbers seen so far as a list of disjoint intervals.</p>

<p style="user-select: auto;">Implement the <code style="user-select: auto;">SummaryRanges</code> class:</p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">SummaryRanges()</code> Initializes the object with an empty stream.</li>
	<li style="user-select: auto;"><code style="user-select: auto;">void addNum(int value)</code> Adds the integer <code style="user-select: auto;">value</code> to the stream.</li>
	<li style="user-select: auto;"><code style="user-select: auto;">int[][] getIntervals()</code> Returns a summary of the integers in the stream currently as a list of disjoint intervals <code style="user-select: auto;">[start<sub style="user-select: auto;">i</sub>, end<sub style="user-select: auto;">i</sub>]</code>. The answer should be sorted by <code style="user-select: auto;">start<sub style="user-select: auto;">i</sub></code>.</li>
</ul>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong class="example" style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input</strong>
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
<strong style="user-select: auto;">Output</strong>
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

<strong style="user-select: auto;">Explanation</strong>
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // return [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">0 &lt;= value &lt;= 10<sup style="user-select: auto;">4</sup></code></li>
	<li style="user-select: auto;">At most <code style="user-select: auto;">3 * 10<sup style="user-select: auto;">4</sup></code> calls will be made to <code style="user-select: auto;">addNum</code> and <code style="user-select: auto;">getIntervals</code>.</li>
</ul>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Follow up:</strong> What if there are lots of merges and the number of disjoint intervals is small compared to the size of the data stream?</p>
</div>