import logo from './logo.svg';
import './App.css';
import FormData from './FormData';
import DeviceCard from './DeviceCard';

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <p>
          Smart Home
        </p>
      </header>
      <div className="background-image">
          <FormData/>
          <DeviceCard/>
      </div>
    </div>
  );
}

export default App;
