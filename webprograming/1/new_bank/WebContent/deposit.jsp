<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%>
<body style="background-color:#E0F8F7">
<%
String id = (String)session.getAttribute("id");
%>
<div align="center">
<h2>입 금</h2>
<hr>
<font color="blue"><%=id%></font>님, 입금액을 적어주세요. <br>
<hr><p>
<form method="post" action="deposit_insert_p.jsp">
입금: <input type="text" name="deposit"/> 원 <p>
<input type="submit" value="입금진행"/>
</form>
<a href = "menu.jsp" > 메뉴로 돌아가기 </a> <p>
</div>
</body>