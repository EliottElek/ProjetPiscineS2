import React from "react";
import { List, Grid } from "@mui/material";
import MessageForm from "./MessageForm/MessageForm";
import Message from "./Message/Message";
import AppBar from "./AppBar/AppBar";
const styles = {
  grid: { height: "100vh", background: "#36393f" },
  middleContainer: {
    overflowY: "auto",
  },
  header: {
    display: "flex",
    alignItems: "center",
    justifyContent: "space-around",
    color: "#D9E2EC",
    borderBottom: "solid 1.5px rgb(35, 36, 40, 0.5)",
  },
  message: {
    background: "#36393f",
    padding: "5px",
  },
  item: {
    background: "transparent",
  },
};

const Channel = ({ messages, channel, addMessage }) => {
  return (
    <Grid sx={styles.grid} container direction="column">
      <Grid style={styles.header} item xs={1} md={1} lg={1} xl={1}>
        <AppBar channel={channel} />
      </Grid>
      <Grid
        id="middleContainer"
        item
        xs={10}
        md={10}
        lg={10}
        xl={10}
        style={styles.middleContainer}
      >
        <List sx={{ width: "100%", bgcolor: "transparent" }}>
          {messages?.map((message) => (
            <Message message={message} />
          ))}
        </List>
      </Grid>
      <Grid item xs={1} md={1} lg={1} xl={1}>
        <MessageForm addMessage={addMessage} />
      </Grid>
    </Grid>
  );
};

export default Channel;
