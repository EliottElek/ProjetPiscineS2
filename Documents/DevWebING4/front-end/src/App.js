import React, { useState } from "react";
import CssBaseline from "@material-ui/core/CssBaseline";
import { createTheme, ThemeProvider } from "@mui/material/styles";
import user from "./dummy/user";
import { BrowserRouter as Router, Switch, Route } from "react-router-dom";
import Container from "./components/Container/Container";
import SignUpPage from "./components/SignUpPage/SignUpPage";
import MaterialUISwitch from "./components/DarkThemeSwitch/DarkThemeSwitch";

function App() {
  const [loggedIn, setIsLoggedIn] = useState(true);
  const logOut = () => {
    setIsLoggedIn(false);
  };
  const darkTheme = createTheme({
    palette: {
      mode: "dark",
      primary: {
        main: "#424242",
      },
      secondary: {
        main: "#E5E5E5",
      },
    },
  });
  const lightTheme = createTheme({
    palette: {
      mode: "light",
      primary: {
        main: "#FFFFFE",
      },
      unReadBackground: {
        main: "#6588DE",
      },
      unReadTextColor: {
        main: "#FDFDFE",
      },
      secondary: {
        main: "#E5E5E5",
      },
    },
  });
  const [theme, setTheme] = useState(true);

  const handleChangeTheme = (event) => {
    setTheme(event.target.checked);
  };
  return (
    <div className="App" style={{ maxHeight: "100%" }}>
      <Router>
        <ThemeProvider theme={theme ? darkTheme : lightTheme}>
          <CssBaseline />
          <Switch>
            <Route exact path="/">
              {loggedIn ? (
                <Container
                  style={{ maxHeight: "100%" }}
                  user={user}
                  logOut={logOut}
                  switchDark={
                    <MaterialUISwitch
                      sx={{ m: 0.2 }}
                      onChange={handleChangeTheme}
                      label="Change mode"
                      checked={theme}
                    />
                  }
                ></Container>
              ) : (
                <SignUpPage />
              )}
            </Route>
          </Switch>
        </ThemeProvider>
      </Router>
    </div>
  );
}

export default App;
