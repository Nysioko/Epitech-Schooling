// const mysql = require('mysql2')

// const connection = mysql.createConnection({
//     host: process.env.MYSQL_HOST,
//     user: process.env.MYSQL_USER,
//     password: process.env.MYSQL_ROOT_PASSWORD,
// })

// const email = ""
// const password = ""
// const name = ""
// const firstname = ""

// // syntaxe : INSERT INTO table(champ1, champ2) VALUES(valeur1, valeur2);
// // insérer un truc dans la base de données
// // connection.execute("INSERT INTO user(email, password, name, firstname) VALUES (?, ?, ?, ?);", [email, password, name, firstname])

// // syntaxe d'une requête : SELECT champ FROM table;
// connection.query("SELECT * FROM user;", (err, results, fields) => {
//     console.log(results)
// })

// /* function (a) {
//     return b;
// }
// ==
// a => b */

// -----------------------------------------------------------------
require("dotenv").config()

const express = require('express')
const app = express()
const port = 27000

const bodyParser = require('body-parser')
app.use(bodyParser.json()) // support json encoded bodies
app.use(bodyParser.urlencoded({ extended: true })) // support encoded bodies

const auth = require("../src/routes/auth/auth.js")
app.use("/", auth)

app.listen(port, () => {
    console.log(`App currently listening at http://localhost:${port}`)
})