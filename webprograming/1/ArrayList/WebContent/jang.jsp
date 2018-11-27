<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.util.ArrayList" %>
<body style="background-color:yellow">
<h4>장바구니 품목 리스트</h4>
<% 
ArrayList<String> arr = (ArrayList<String>)session.getAttribute("car_s");
%>
<form method="post" action="delete.jsp">
<%for (int i=0; i<arr.size(); i++) {%>
<input type="radio" name="delno_n" value="<%=i%>" /> <%=arr.get(i)%> <br>
<%}%>
<p>
<input type="submit" value="선택항목삭제"> &nbsp;&nbsp; 
<a href="jang.jsp">전체 구매 (나중 추가)</a> <p>
<a href = "menu.jsp"> 메뉴로 돌아가기 </a> 
</form> 
</body>