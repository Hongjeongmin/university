<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%>
<%
request.setCharacterEncoding("UTF-8");
String id = (String)session.getAttribute("id");
%>
<body style="background-color:lime">
<h2>전체메뉴</h2>
<hr>
<font color="blue"><%=id%></font>님, 어떤 업무를 하시겠습니까? <br>
<hr><p>
<ul>
<li><a href = "deposit.jsp">입금</a></li>
<li><a href = "withdraw.jsp">출금</a></li>
<li><a href = "balance.jsp">자액조회</a></li>
<li><a href = "mytradelist.jsp">내 거래 내역 조회</a></li>
<li><a href = "trnasfer.jsp">이체</a></li>
<li><a href = "check_pw.jsp">회원정보변경</a></li>
<li><a href = "secede.jsp">회원탈회</a></li>
<li><a href = "logout.jsp">logout</a></li>
<% if(id!=null) {
if(id.equals("admin")) { %>  
<li><a href = "alldatalist.jsp">전체 데이터(관리자용)</a>
<% }} %>
</ul>
</body>