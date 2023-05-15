//#include <QDebug>   // 这里的作用是在终端输出信息
//#include <QString>

//// 数据库相关
//#include <QtSql>
//#include <QSqlDatabase> // 数据库头文件
//#include <QSqlQuery>    // sql查询
//#include <QSqlTableModel>   // 用来显示数据库中数据表的数据，实现对数据的编辑、插入、删除等操作。实现数据的排序和过滤
//#include <QSqlError>    // 处理 sql 报错信息

//void sql_link();     // 数据库链接
//void into();    // 插入数据
//void delete_data(); // 删除数据
//void querys();  // 查询数据
//void qusery_all();   // 查询所有数据
//void update();  // 修改数据


//void sql_link()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("127.0.0.1");  // 连接本地主机
//    db.setPort(3306);   // 端口
//    db.setDatabaseName("HearthStone");    // 数据库名称
//    db.setUserName("root");    // 登陆数据库的用户名
//    db.setPassword("159357");   // 登陆数据库的用户密码

//    bool ok = db.open();    // ·获取是否打开
//    if (ok)
//    {
//        // 链接成功时
//    }
//    else
//    {
//        qDebug()<<"打开失败："<<db.lastError().text(); // 返回数据库报错的原因
//    }

//    // 开始使用
//    // 用 career表，career_id列 做试验

//    // into();  // 插入数据
//    // delete_data();   // 删除数据
//    // update();    // 修改数据
//    // querys();    // 查询数据
//    // qusery_all();    // 查询所有数据
//}

//// query.value(0).toString();
//// query.value(0) 获取 query指向当前位置 的数据
//// 0 表示返回的字段：从左到右 0-n

//// QString(" %1 %2").arg(变量1).arg(变量2)
//// 从左向右 0-n

//void into()    // 插入数据
//{
//    QString career_id = "hero";

//    if(career_id == "") //检查信息是否填写完整
//    {
//        qDebug("请输入完整的信息");
//    }
//    else
//    {
//        // 插入语法
//        // QString("insert into 表名(字段1, 字段2) values('%1', '%2')").arg(变量1).arg(变量2)
//        QString str = QString("insert into career(career_id) values('%1')").arg(career_id);
//        QSqlQuery query;
//        query.exec(str); //执行插入操作
//        qDebug() << "插入成功";
//    }
//}

//void delete_data()  // 删除数据
//{
//    QString career_id = "aaa";

//    if(career_id ==  "")
//    {

//        qDebug("请输入需要删除的数据");
//    }

//    else
//    {
//        // 从数据库中查询是否有目标数据
//        QSqlQuery query;

//        // 查询语法
//        //  select * from 表名 where 条件
//        QString temp = QString("select * from career where career_id = '%1'").arg(career_id);
//        query.exec(temp);

//        QString deletename;
//        while (query.next())
//        {
//            deletename = query.value(0).toString();
//        }
//        if(deletename == "")
//        {
//            QString a = QString("%1不存在，删除失败").arg(career_id);
//            qDebug() << a;
//        }
//        else
//        {
//            // 删除语法
//            // delete from 表名 where 条件
//            QString str =  QString("delete from career where career_id = '%1'").arg(career_id);
//            query.exec(str);//删除信息
//            qDebug() << "删除成功";
//        }
//    }
//}

//void querys() // 查询数据
//{
//    QString career_id = "萨满祭司";     // 创建待查询数据

//    if(career_id == "")    // 检查待查询的是否是空
//    {
//        qDebug("请输入需要查询的数据");
//    }
//    else
//    {
//        // 查询数据语法
//        // QString("select 字段名 from 表名 where 条件列表 ").arg(变量)
//        // 字段名用 * 表示所有字段
//        QString str = QString("select * from career where career_id = '%1' ").arg(career_id);
//        QSqlQuery query;
//        qDebug() << query.exec(str);    // 返回是否 成功执行查询语句

//        while (query.next())
//        {
//            qDebug() << "执行成功";
//            qDebug() << "职业：" << query.value(0);
//        }

//        if(query.value(0) == "")
//        {
//            QString err = QString("%1不存在，请重新输入").arg(career_id);
//            qDebug() << err;
//        }
//        else
//        {
//            qDebug() << "查询成功";
//        }
//    }
//}

//void qusery_all()   // 查询所有数据
//{
//    QString career_id[100];//用来存储从数据库中找出来的信息
//    int i = 0;
//    QSqlQuery query;
//    // 查询语法
//    // select * from 表名
//    query.exec("select * from career");//查询所有的信息
//    while(query.next())
//    {
//        career_id[i] = query.value(0).toString();
//        i++;
//    }
//    int j = 0;
//    for(j = 0; j < i; j++)
//    {
//        QString str = QString("职业：%1").arg(career_id[j]);
//        qDebug() << str;
//    }
//}

//void update()  // 修改数据
//{
//    QString career_id = "hero";

//    // 查找有无待修改信息
//    if(career_id == "NULL")
//    {
//        qDebug() << "请输入需要修改的数据";
//    }
//    else
//    {
//        // 查找数据
//        // select * from 表名 where 条件
//        QString temp = QString("select * from career where career_id = '%1'").arg(career_id);
//        QSqlQuery query;
//        query.exec(temp);

//        QString a;
//        while (query.next())
//        {
//            a = query.value(0).toString();
//        }

//        if(a == "")
//        {
//            QString b = QString("%1不存在，修改失败").arg(career_id);
//            qDebug() << b;
//         }
//        else
//        {
//            // 更新数据语法
//            // update 表名 set 字段 = 值 where 条件
//            temp = QString("update career set career_id = 'aaa' where career_id = '%1' ").arg(career_id);
//            query.exec(temp);
//            qDebug() << "修改成功";
//        }
//    }
//}
