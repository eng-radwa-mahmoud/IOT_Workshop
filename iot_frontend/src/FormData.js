import "./FormData.css";
import Axios from "axios"
import {useState, useEffect} from 'react'

export default function FormData() {

  const [ID, setID] = useState([])
  const [name, setName] = useState([])


const createdevice = () => {
  Axios.post("http://localhost:3001/createdevice",{
    identifier:ID,
    name:name,
    status:false
  })
.then(res => {
  console.log(res.data);
})
}

  return (
    <>
      
      <div className="form">
        <h1>Register New Device</h1>
        <form>
          {/* <label for="name">Name:</label> */}
          <input
            /* ref={id_value} */
            type="text"
            name="ID"
            placeholder="ID..."
            onChange={e => setID(e.target.value)}
          ></input>
          <input
           /*  ref={name_value} */
            type="text"
            name="name"
            placeholder="Name..."
            onChange={e => setName(e.target.value)}
          ></input>
          <button onClick={createdevice} type="button">
            Add
          </button>
        </form>
      </div>
    </>
  );
}