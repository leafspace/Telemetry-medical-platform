<%@ page import="java.util.ArrayList" %>
<%@ page import="cn.cslg.tools.GetData" %>
<%--
  Created by IntelliJ IDEA.
  User: 18852
  Date: 2017/3/11
  Time: 9:19
  To change this template use File | Settings | File Templates.
--%>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
  response.setHeader("refresh", "5");
  GetData getData = new GetData();
  ArrayList<String> informations = getData.getInformations();
%>
<html>
  <head>
    <title>$Title$</title>
  </head>
  <body>
    <table border="1">
      <tr>
        <td>
          消息
        </td>
      </tr>
      <%
          for(int i = 0; i < informations.size(); ++i){
      %>
            <tr><td><%=informations.get(i)%></td></tr>
      <%
          }
      %>
    </table>
  </body>
</html>
