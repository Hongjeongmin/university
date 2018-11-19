<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%>
<body style="background-color:#E0F8F7">
<%
String id = (String)session.getAttribute("id");
%>
<div align="center">
<h2>이 체</h2>
<hr>
<font color="blue"><%=id%></font>님, 이체할분 id와 금액 입력해주세요. <br>
<hr><p>
<form method="post" action="trnasfer_check_id.jsp">
받는사람:	<input type="text" name="you"/> <p>
금액: <input type="text" name="money"/> 원 <p>
<input type="submit" value="이체하기"/>
</form>
<a href = "menu.jsp" > 메뉴로 돌아가기 </a> <p>
</div>
</body>