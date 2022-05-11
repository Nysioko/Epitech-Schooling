const mysql2 = require("mysql2")
const bcrypt = require("bcryptjs")
const jwt = require("jsonwebtoken")

const HTTP_SUCCESS = 200
const HTTP_BAD_REQUEST = 400

const connection = mysql2.createConnection({
    host: process.env.MYSQL_HOST,
    user: process.env.MYSQL_USER,
    password: process.env.MYSQL_ROOT_PASSWORD,
    database: "epytodo"
})

const express = require('express')
const router = express.Router()

// REGISTER THE USER N THE DATABASE
router.post('/register', (req, res) => {
    const email = req.body.email
    const password = req.body.password
    const name = req.body.name
    const firstname = req.body.firstname

    if (email === undefined || password === undefined || name === undefined || firstname === undefined) {
        res.sendStatus(HTTP_BAD_REQUEST).end()
    }

    else {
        connection.execute("INSERT INTO user(email, password, name, firstname) VALUES (?, ?, ?, ?);", [email, bcrypt.hashSync(password), name, firstname], (err, results, fields) => {
            if (err) {
                res.status(403).json({
                    "msg": "account already exists"
                }).end()
            }
            else {
                const token = jwt.sign({ username: req.body.email }, process.env.TOKEN, { expiresIn: "3600s" })
                res.status(200).json({
                    "token": token
                }).end()
            }
        })
    }
})

//LOGIN THE USER
router.post('/login', (req, res) => {
    connection.query("SELECT * FROM user WHERE email = '" + req.body.email + "';", (err, results, fields) => {
        const user = results[0]

        if (!user) {
            return res.status(401).json({
                "msg": "Invalid Credentials"
            })
        }

        bcrypt.compare(req.body.password, user.password).then(
            (valid) => {
                if (!valid) {
                    return res.status(401).json({
                        "msg": "Invalid Credentials"
                    })
                }
                const token = jwt.sign({ username: req.body.email }, process.env.TOKEN, { expiresIn: "3600s" })
                res.status(200).json({
                    token: token
                })
            }
        ).catch(
            (error) => {
                    console.log(error)
                    res.status(500).json({
                    "msg": "internal server error"
                })
            }
        )
    })
})

module.exports = router