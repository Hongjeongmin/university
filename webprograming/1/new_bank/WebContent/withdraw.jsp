<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%>
<body style="background-color:#E0F8F7">
<%
String id = (String)session.getAttribute("id");
%>
<div align="center">
<h2>출 금</h2>
<hr>
<font color="blue"><%=id%></font>님, 얼마를 출금하시겠습니까? <br>
<hr><p>
<form method="post" action="withdraw_check.jsp">
출금: <input type="text" name="withdraw"/> 원 <p>
<input type="submit" value="출금진행"/> </form>
<a href = "menu.jsp" > 메뉴로 돌아가기 </a> <p>
</div>
</body>