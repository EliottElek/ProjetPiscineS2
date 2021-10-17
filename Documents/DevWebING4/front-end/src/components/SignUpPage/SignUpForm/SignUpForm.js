import React, { useState } from "react";
import { FormControl, TextField } from "@mui/material";
const SignUpForm = () => {
  const [firstname, setFirstname] = useState("");
  const [lastname, setLastname] = useState("");
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");

  return (
    <div>
      <FormControl sx = {{bgcolor:"primary.main"}}>
        <TextField
        color= "primary"
          id="outlined-password-input"
          label="Password"
          type="password"
          placeholder = 'Firstname'
          autoComplete="current-password"
          value={firstname}
          onChange={(event) => {
            setFirstname(event.target.value);
          }}
        ></TextField>
        <TextField
          id="outlined-password-input"
          label="Password"
          type="password"
          autoComplete="current-password"
          value={lastname}
          onChange={(event) => {
            setLastname(event.target.value);
          }}
        ></TextField>
        <TextField
          id="outlined-password-input"
          label="Password"
          type="password"
          autoComplete="current-password"
          value={email}
          onChange={(event) => {
            setEmail(event.target.value);
          }}
        ></TextField>
        <TextField
          id="outlined-password-input"
          label="Password"
          type="password"
          autoComplete="current-password"
          value={password}
          onChange={(event) => {
            setPassword(event.target.value);
          }}
        ></TextField>
      </FormControl>
    </div>
  );
};

export default SignUpForm;
